#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.hpp"
#include <QFontDatabase>
#include <QFile>
// The database
database db; // Format: SQLite

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LoadResources();
    qMain();
}

void MainWindow::LoadResources(){
    // ------------------------------------ Load resources, fonts, etc. ------------------------------------
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Black.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-BlackItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Bold.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-BoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-ExtraBold.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-ExtraBoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-ExtraLight.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-ExtraLightItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Italic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Light.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-LightItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Medium.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-MediumItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Regular.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-SemiBoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-Thin.ttf");
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/WorkSans-ThinItalic.ttf");
    // Variable fonts (needed?)
    QFontDatabase::addApplicationFont(":/resources/assets/fonts/variable/WorkSans-VariableFont_wght.ttf");



    // ------------------------------------ Load the external CSS file ------------------------------------
    QFile styleFile(":/otherfiles/assets/css/finalproject.css");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(styleSheet);
        styleFile.close();
    }
    else {
        qDebug() << "Failed to open CSS file:" << styleFile.errorString();
    }

    // ------------------------------------ Load an image from file ------------------------------------
    QIcon searchIcon(":/otherfiles/assets/images/searchImg.png");
    QIcon settingIcon(":/otherfiles/assets/images/settings.png");
    QIcon userIcon(":/otherfiles/assets/images/user.png");
    QIcon headphonesIcon(":/otherfiles/assets/images/headphones.png");
    QIcon backIcon(":/otherfiles/assets/images/backward.png");
    QIcon playIcon(":/otherfiles/assets/images/play.png");
    QIcon forwardIcon(":/otherfiles/assets/images/forward.png");
    QPixmap playlistImage(":/otherfiles/assets/images/playlist.jpg");

    QIcon trackIcon(":/otherfiles/assets/images/tracks.png");
    QIcon albumIcon(":/otherfiles/assets/images/album.png");
    QIcon playlistIcon(":/otherfiles/assets/images/playlist.png");
    QIcon languageIcon(":/otherfiles/assets/images/lang.png");
    QIcon usermanIcon(":/otherfiles/assets/images/user_big.png");
    QIcon trackmanIcon(":/otherfiles/assets/images/trackman.png");
    QIcon reportsIcon(":/otherfiles/assets/images/reports.png");

    QIcon englishIcon(":/otherfiles/assets/images/englishflag.png");
    QIcon spanishIcon(":/otherfiles/assets/images/spanishflag.png");

    // -------------------------------------------- Apply icons --------------------------------------------

    // Mainwindow
    setWindowTitle("Music in Action");
    setWindowIcon(QIcon(headphonesIcon));

    // Setting initial windows
    ui->mainStackedWidget->setCurrentIndex(4);
    ui->managementTab_fp->setCurrentIndex(0);
    ui->trackManagementSub->setCurrentIndex(0);

    // Header
    ui->user_loggedin->setIcon(QIcon(userIcon));
    ui->settings->setIcon(QIcon(settingIcon));

    // Search Buttons
    ui->search_submit->setIcon(QIcon(searchIcon));
    ui->editSearchButton->setIcon(QIcon(searchIcon));

    // Play Area Icons
    ui->back_pa->setIcon(QIcon(backIcon));
    ui->back_pa->setIcon(QIcon(backIcon));
    ui->play_pause_pa->setIcon(QIcon(playIcon));
    ui->forward_pa->setIcon(QIcon(forwardIcon));

    int h = ui->track_image_pa->height();    // Get the height & width of the QLabel
    int w = ui->track_image_pa->width();
    ui->track_image_pa->setPixmap(playlistImage.scaled(w, h));

    // Settings window buttons
    ui->viewSongsButton->setIcon(QIcon(trackIcon));
    ui->viewSongsButton->setIconSize(QSize(35, 35));

    ui->viewAlbumsButton->setIcon(QIcon(albumIcon));
    ui->viewAlbumsButton->setIconSize(QSize(35, 35));

    ui->viewPlaylistButton->setIcon(QIcon(playlistIcon));
    ui->viewPlaylistButton->setIconSize(QSize(35, 35));

    ui->languageButton->setIcon(QIcon(languageIcon));
    ui->languageButton->setIconSize(QSize(35, 35));

    ui->userManagementButton->setIcon(QIcon(usermanIcon));
    ui->userManagementButton->setIconSize(QSize(35, 35));

    ui->trackManagementButton->setIcon(QIcon(trackmanIcon));
    ui->trackManagementButton->setIconSize(QSize(35, 35));

    ui->reportButton->setIcon(QIcon(reportsIcon));
    ui->reportButton->setIconSize(QSize(35, 35));

    // Connect the combo box to track settings window
    connect(ui->trackManagementcomboBox, SIGNAL(currentIndexChanged(int)), ui->trackManagementSub, SLOT(setCurrentIndex(int)));

    // Translation buttons
    ui->englishButton->setIcon(QIcon(englishIcon));
    ui->englishButton->setIconSize(QSize(125, 125));

    ui->spanishButton->setIcon(QIcon(spanishIcon));
    ui->spanishButton->setIconSize(QSize(125, 125));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::qMain(){
    // Main entry point
    // Setup database
    // --------------------------------- DEBUG ----------------------------------------------------------------------------------------------
    db = *new database();
    db.setDatabase("userdata");
    odb::sqlite::database database_context = db.getDatabase();

    odb::transaction t(database_context.begin());
    // Execute SQL commands to create the table
    database_context.execute("CREATE TABLE IF NOT EXISTS Person (id INTEGER PRIMARY KEY, first TEXT, last TEXT, age INTEGER)");
    t.commit();
    // -------------------------------- END_DEBUG --------------------------------------------------------------------------------------------
}

void MainWindow::on_settings_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(2);
}


void MainWindow::on_search_submit_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(8);
}


void MainWindow::on_reportButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(7);
}


void MainWindow::on_your_playlists_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(6);
}


void MainWindow::on_trackManagementButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(1);
}


void MainWindow::on_userManagementButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(5);
}


void MainWindow::on_all_tracks_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}


void MainWindow::on_all_albums_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(3);
}


void MainWindow::on_viewSongsButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(4);
}


void MainWindow::on_viewAlbumsButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(3);
}


void MainWindow::on_viewPlaylistButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(6);
}


void MainWindow::on_languageButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(9);
}

