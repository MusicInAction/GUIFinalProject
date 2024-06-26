// For retrieving various Windows things
// Such as the username, computer name, etc.
#include <Windows.h>
#include <Lmcons.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Include the database class-schemas
#include "Track.hpp"
#include "Track_Playlist.hpp"
#include "Artists.hpp"
#include "Albums.hpp"
#include "Playlist.hpp"
#include "WindowsAccount.hpp"
#include "Roles.hpp"

// Include the database mappings
#include "Track-odb.hxx"
#include "Track_Playlist-odb.hxx"
#include "Artists-odb.hxx"
#include "Albums-odb.hxx"
#include "Playlist-odb.hxx"
#include "WindowsAccount-odb.hxx"
#include "Roles-odb.hxx"

#include <QMessageBox>

// Include command-line output
#include <QDebug>

void createTables(odb::sqlite::database &database_context) {
    try {
	// Create the tables
    // PLEASE NOTE: The tables are created in a specific order to avoid errors
    // Please only edit if needed + if you know what you are doing, because the order is important
    // Otherwise, please ask for help or assistance


    // Left-hand side (Artists, Albums, Genres) -- Autonoumous tables/classes

    // Create the Artists table
    database_context.execute("CREATE TABLE IF NOT EXISTS Artists (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name TEXT)");
    // Create the Albums table
    database_context.execute("CREATE TABLE IF NOT EXISTS Albums (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, title TEXT, release_date TEXT)");
    // Create the Genres table
    database_context.execute("CREATE TABLE IF NOT EXISTS Genres (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, title TEXT)");

    // Right-hand side (Track, Playlist, Track_Playlist, Track_Playcount, Windows_Account) -- Autonomous tables/classes

    // Create the Playlist table
    database_context.execute("CREATE TABLE IF NOT EXISTS Playlist (id INTEGER PRIMARY KEY, name TEXT, year TEXT, duration REAL)");
    // Create the Roles table
    database_context.execute("CREATE TABLE IF NOT EXISTS Roles (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name TEXT)");


    // Center-Down (Track_Playcount, Track_Playlist) -- Mix of Autonomous + Dependent tables/classes
    
    // Create the Windows_Account table (independent)
    database_context.execute(std::string("CREATE TABLE IF NOT EXISTS Windows_Account (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, username TEXT, role_id INTEGER, ") +
                             std::string("FOREIGN KEY(role_id) REFERENCES Roles(id) ON DELETE CASCADE)"));

    // Dependent tables

    // Create the Track table
    database_context.execute(std::string("CREATE TABLE IF NOT EXISTS Track (id INTEGER PRIMARY KEY, title TEXT, artist_id INTEGER, album_id INTEGER, year TEXT, genre_id INTEGER,") +
        std::string("lyrics TEXT, duration REAL, file_location TEXT, cover_art BLOB, cover_art_size INTEGER, ") + 
        std::string("FOREIGN KEY(artist_id) REFERENCES Artists(id) ON DELETE CASCADE, FOREIGN KEY(album_id) REFERENCES Albums(id) ON DELETE CASCADE, FOREIGN KEY(genre_id) REFERENCES Genres(id) ON DELETE CASCADE)"));

    // Create the Track_Playlist table
    database_context.execute(std::string("CREATE TABLE IF NOT EXISTS Track_Playlist (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, track_id INTEGER, playlist_id INTEGER, ") +
                             std::string("FOREIGN KEY(track_id) REFERENCES Track(id) ON DELETE CASCADE, FOREIGN KEY(playlist_id) REFERENCES Playlist(id) ON DELETE CASCADE)"));

    // Create the Track_Playcount table
    database_context.execute(std::string("CREATE TABLE IF NOT EXISTS Track_Playcount (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, user_id INTEGER, ") +
                             std::string("track_id INTEGER, count INTEGER, FOREIGN KEY(track_id) REFERENCES Track(id) ON DELETE CASCADE, FOREIGN KEY(user_id) REFERENCES Windows_Account(id) ON DELETE CASCADE)"));
    }
    catch (const odb::exception& e) {
        qDebug() << e.what();
    }
    catch (const std::exception& e) {
        qDebug() << e.what();
    }
}

void MainWindow::qMain() {
    // Main entry point
    // Setup database
    db = *new database();
    db.setDatabase("userdata");
    odb::sqlite::database database_context = db.getDatabase();
    odb::transaction t(database_context.begin());

    // Create the tables
    createTables(database_context);

    // Set the current user and role
    // https://stackoverflow.com/a/11587467/10976415
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserNameA(username, &username_len);

    // Get the group name and check if they're under "Administrators"
    // https://stackoverflow.com/a/26496232/10976415
    PSID administrators_group = NULL;
    SID_IDENTIFIER_AUTHORITY nt_authority = SECURITY_NT_AUTHORITY;
    BOOL result = AllocateAndInitializeSid(&nt_authority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &administrators_group);
    BOOL is_admin = FALSE;


    // Check and see if "User" and "Administrator" roles exist
    // If they don't, create them

    Roles* query_roles = database_context.query_one<Roles>(odb::query<Roles>::name == "User");
    if (query_roles == nullptr) {
        Roles user_role("User");
        query_roles = &user_role;
        database_context.persist(user_role);
    }

    Roles* query_admin_roles = database_context.query_one<Roles>(odb::query<Roles>::name == "Administrator");
    if (query_admin_roles == nullptr) {
        Roles admin_role("Administrator");
        query_admin_roles = &admin_role;
        database_context.persist(admin_role);
    }

    Roles* query_banned_roles = database_context.query_one<Roles>(odb::query<Roles>::name == "Banned");
    if (query_banned_roles == nullptr) {
        Roles banned_role("Banned");
        query_banned_roles = &banned_role;
        database_context.persist(banned_role);
    }

    if (result)
    {
        CheckTokenMembership(NULL, administrators_group, &is_admin);
        FreeSid(administrators_group);
    }

    // Check if the user exists
    Windows_Account* query_user = database_context.query_one<Windows_Account>(odb::query<Windows_Account>::username == username);
	// Check if the database is empty
	odb::result<Windows_Account> all_users = database_context.query<Windows_Account>();
	bool is_empty = all_users.begin() == all_users.end();

    if (query_user != nullptr && query_user->AccessLevel() == NULL) {
        // The user exists
        // Update the user's role
        query_user->SetAccessLevel(is_admin ? query_admin_roles : (is_empty? query_admin_roles: query_roles));
        database_context.update(*query_user);

        // Set the current user
        currentUser = *query_user;
    }
    else if (query_user == nullptr) {
        // Create the Windows_Account object
        currentUser = Windows_Account(username, is_admin ? query_admin_roles : (is_empty ? query_admin_roles : query_roles));

        // Persist this new user
        // This will be used to track the user's listening habits
        database_context.persist(currentUser);
    }
    else if (query_user != nullptr) {
        // Set the current user
        currentUser = *query_user;
    }

    current_role = (Roles*)(currentUser.AccessLevel());
	if (current_role == nullptr) {
		current_role = query_roles;
	}
    // If the `currentUser` has the role of "Banned", then we should not allow them to use the application
    if (current_role->Name() == "Banned") {
        // Disable all the navigation panes
        ui->header->setVisible(false);
        ui->play_area->setVisible(false);

        ui->mainStackedWidget->setCurrentWidget(ui->userIsBannedPage);
        t.commit();
        return; // Abort the application
    }

    if (current_role->Name() == "User") {
        // Hide some options
		ui->userManagementButton->setVisible(false);
        ui->managementTab_fp->setTabVisible(0, false);
        ui->managementTab_fp->setTabVisible(1, false);
        ui->managementTab_fp->setTabVisible(2, false);
		ui->adminModeRoleFrame->setVisible(false);
    }

    // Update the UI username field
    ui->user_loggedin->setText(username);
    ui->label_sp_2->setText(QString::fromStdString(username) + "'s Settings");

    // Commit the transaction
    t.commit();

    // Update the UI
    ui->mainStackedWidget->setCurrentWidget(ui->welcomePage);
    LoadAllTracksPage(ui->libraryListView, QSize(125, 30), QSize(16, 16));

    // Connect our signals and slots
    // Connect the combobox to run LoadReportPage when the combobox is changed
    connect(ui->reportTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        LoadReportPage();
    });

	// Connect the tab widget to run LoadTrackManagementPage when the tab is changed
	connect(ui->managementTab_fp, &QTabWidget::currentChanged, [=](int index) {
		// Load the report page
		LoadTrackManagementPage();
	});

    // Connect the audio output to stop itself once the media has finished playing
    QAudioOutput::connect(player, &QMediaPlayer::playbackStateChanged, [=](QMediaPlayer::PlaybackState state) {
        // Are we finished?
        if (state == QMediaPlayer::StoppedState) {
            // Stop the audio output
			player->stop();
			// Change the controls icon to a stop icon
			ui->play_pause_pa->setIcon(stopIcon);
        }
        // Are we switching tracks?
         if (state == QMediaPlayer::PlayingState) {
             // Change the controls icon to a pause icon
             ui->play_pause_pa->setIcon(pauseIcon);
         }
         // Are we still playing?
         /*if (state == QMediaPlayer::PlayingState) {
             return;
         }*/
         // Are we paused?
        if (state == QMediaPlayer::PausedState) {
            // Do nothing (for now)
        }
		// Are we in an error state

    //// Check if there was an error setting the media content
    //    if (state == QMediaPlayer::erro) {
    //        qDebug() << "----Error setting media content----";
    //        qDebug() << "Error:" << player->error() << ": " << player->errorString();
    //        qDebug() << "File path:" << track_url;

    //        // Check if the file was not found
    //        if (state == QMediaPlayer::ResourceError) {
    //            qDebug() << "----Media not found----";
    //            qDebug() << "File path:" << track_url;
    //            QMessageBox msgBox;
    //            msgBox.setWindowTitle("Media error");
    //            msgBox.setIcon(QMessageBox::Critical);
    //            msgBox.setText("<FONT COLOR='BLACK'>The requested media was not found.</ FONT>");
    //            msgBox.exec();
    //            try {
    //                // Erase the file from the database
    //                database_context.erase_query<Track>(odb::query<Track>::id == currentTrack.Id());
    //            }
    //            catch (odb::exception& e) {
    //                qDebug() << e.what();
    //            }

    //            // Refresh the UI data
    //            ui->allTracksListView->model()->deleteLater();
    //            ui->allTracksListView->setModel(nullptr);

    //            ui->libraryListView->model()->deleteLater();
    //            ui->allTracksListView->model()->deleteLater();
    //            ui->allTracksListView->setModel(nullptr);

    //            t.commit(); // Clean-up after ourselves



    //            // Update the UI
    //            LoadAllTracksPage(ui->allTracksListView, QSize(125, 175), QSize(100, 100));
    //            LoadAllTracksPage(ui->libraryListView, QSize(125, 30), QSize(16, 16));

    //            return;
    //        }
    //        t.commit();
    //        return;
    //    }


        });

    // -------------------------------- BEGIN_DEBUG --------------------------------------------------------------------------------------------
    // The following code displays usage of the database classes and their mappings
    // It shows how to create playlists, artists, albums, genres, and tracks
    // Please note that this code is for debugging purposes only
    // 
    //   // .. Create a new playlist
    //   Playlist playlist("My Playlist", "2015");

    //   // Create a new artist
    //   Artists the_beatles("The Beatles");

    //   // Create the two albums (name, year)
    //   Albums one_remastered("1 (Remastered)", "2015");
    //   Albums let_it_be_remastered("Let It Be (Remastered)", "2015");
    //   Genres rock("Rock");

    //   // string title, int* artist_id, string year, string file_location

    //   // Create a new track
    //   Track track("Hey, Jude", &the_beatles, &one_remastered, "1968", 3.50, "C://Users//Downloads//The_Beatles__Hey_Jude.mp3");
    //   Track track2("Let It Be", &the_beatles, &let_it_be_remastered, "1970", 4.00, "C://Users//Downloads//The_Beatles__Let_It_Be.mp3");
    //   
    //   // Rock and roll song using the full track constructor
    //   Track rock_and_roll("Rock and Roll Music", &the_beatles, &one_remastered, &rock, "x", "1964", 1.25, "C://Users//Downloads//The_Beatles__Rock_and_Roll_Music.mp3");

    //   // Add the tracks to the playlist
    //   Track_Playlist playlist_map_0(&track, &playlist); // Track_Playlist.map(playlist, track);
    //   Track_Playlist playlist_map_1(&track2, &playlist); // Track_Playlist.map(playlist, track2);

    //   // Save everything
    //   unsigned long album_0_id, album_1_id, genre_0_id, the_beatles_id, track_0_id, track_1_id, track_2_id, playlist_map_0_id, playlist_map_1_id, playlist_0_id;
    //   try {
    //       the_beatles_id = database_context.persist(the_beatles);
    //       album_0_id = database_context.persist(one_remastered);
    //       album_1_id = database_context.persist(let_it_be_remastered);
    //       genre_0_id = database_context.persist(rock);
    //       track_0_id = database_context.persist(rock_and_roll);
    //       track_1_id = database_context.persist(track);
    //       track_2_id = database_context.persist(track2);

    //       // Playlist and its mappings
    //       playlist_0_id = database_context.persist(playlist);
    //       playlist_map_0_id = database_context.persist(playlist_map_0);
    //       playlist_map_1_id = database_context.persist(playlist_map_1);
    //       
    //   } catch(const odb::exception& e) {
    //       qDebug() << e.what();
       //}
    //   // Execute SQL commands to create the table
    //   //database_context.execute("CREATE TABLE IF NOT EXISTS Person (id INTEGER PRIMARY KEY, first TEXT, last TEXT, age INTEGER)");
    //   t.commit();
       // -------------------------------- END_DEBUG --------------------------------------------------------------------------------------------
}