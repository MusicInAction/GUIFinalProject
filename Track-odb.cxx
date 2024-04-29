// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "Track-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/simple-object-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/simple-object-result.hxx>

namespace odb
{
  // Track
  //

  const char alias_traits<  ::Artists,
    id_sqlite,
    access::object_traits_impl< ::Track, id_sqlite >::artist_id_tag>::
  table_name[] = "\"artist_id\"";

  const char alias_traits<  ::Albums,
    id_sqlite,
    access::object_traits_impl< ::Track, id_sqlite >::album_id_tag>::
  table_name[] = "\"album_id\"";

  const char alias_traits<  ::Genres,
    id_sqlite,
    access::object_traits_impl< ::Track, id_sqlite >::genre_id_tag>::
  table_name[] = "\"genre_id\"";

  struct access::object_traits_impl< ::Track, id_sqlite >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      sqlite::connection&,
      image_type&,
      id_image_type&,
      sqlite::binding&,
      sqlite::binding&)
    {
    }
  };

  access::object_traits_impl< ::Track, id_sqlite >::id_type
  access::object_traits_impl< ::Track, id_sqlite >::
  id (const id_image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::Track, id_sqlite >::id_type
  access::object_traits_impl< ::Track, id_sqlite >::
  id (const image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::Track, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = false;

    // title_
    //
    if (t[1UL])
    {
      i.title_value.capacity (i.title_size);
      grew = true;
    }

    // artist_id_
    //
    t[2UL] = false;

    // album_id_
    //
    t[3UL] = false;

    // genre_id_
    //
    t[4UL] = false;

    // lyrics_
    //
    if (t[5UL])
    {
      i.lyrics_value.capacity (i.lyrics_size);
      grew = true;
    }

    // duration_
    //
    t[6UL] = false;

    // year_
    //
    if (t[7UL])
    {
      i.year_value.capacity (i.year_size);
      grew = true;
    }

    // file_location_
    //
    if (t[8UL])
    {
      i.file_location_value.capacity (i.file_location_size);
      grew = true;
    }

    // cover_art_
    //
    if (t[9UL])
    {
      i.cover_art_value.capacity (i.cover_art_size);
      grew = true;
    }

    // cover_art_size_
    //
    t[10UL] = false;

    return grew;
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_update)
    {
      b[n].type = sqlite::bind::integer;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // title_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.title_value.data ();
    b[n].size = &i.title_size;
    b[n].capacity = i.title_value.capacity ();
    b[n].is_null = &i.title_null;
    n++;

    // artist_id_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.artist_id_value;
    b[n].is_null = &i.artist_id_null;
    n++;

    // album_id_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.album_id_value;
    b[n].is_null = &i.album_id_null;
    n++;

    // genre_id_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.genre_id_value;
    b[n].is_null = &i.genre_id_null;
    n++;

    // lyrics_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.lyrics_value.data ();
    b[n].size = &i.lyrics_size;
    b[n].capacity = i.lyrics_value.capacity ();
    b[n].is_null = &i.lyrics_null;
    n++;

    // duration_
    //
    b[n].type = sqlite::bind::real;
    b[n].buffer = &i.duration_value;
    b[n].is_null = &i.duration_null;
    n++;

    // year_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.year_value.data ();
    b[n].size = &i.year_size;
    b[n].capacity = i.year_value.capacity ();
    b[n].is_null = &i.year_null;
    n++;

    // file_location_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.file_location_value.data ();
    b[n].size = &i.file_location_size;
    b[n].capacity = i.file_location_value.capacity ();
    b[n].is_null = &i.file_location_null;
    n++;

    // cover_art_
    //
    b[n].type = sqlite::bind::blob;
    b[n].buffer = i.cover_art_value.data ();
    b[n].size = &i.cover_art_size;
    b[n].capacity = i.cover_art_value.capacity ();
    b[n].is_null = &i.cover_art_null;
    n++;

    // cover_art_size_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.cover_art_size_value;
    b[n].is_null = &i.cover_art_size_null;
    n++;
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::Track, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // id_
    //
    if (sk == statement_insert)
    {
      int const& v =
        o.id_;

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        v);
      i.id_null = is_null;
    }

    // title_
    //
    {
      ::std::string const& v =
        o.title_;

      bool is_null (false);
      std::size_t cap (i.title_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.title_value,
        i.title_size,
        is_null,
        v);
      i.title_null = is_null;
      grew = grew || (cap != i.title_value.capacity ());
    }

    // artist_id_
    //
    {
      ::Artists* const& v =
        o.artist_id_;

      typedef object_traits< ::Artists > obj_traits;
      typedef odb::pointer_traits< ::Artists* > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& ptr_id (
          obj_traits::id (ptr_traits::get_ref (v)));

        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_image (
          i.artist_id_value,
          is_null,
          ptr_id);
        i.artist_id_null = is_null;
      }
      else
        i.artist_id_null = true;
    }

    // album_id_
    //
    {
      ::Albums* const& v =
        o.album_id_;

      typedef object_traits< ::Albums > obj_traits;
      typedef odb::pointer_traits< ::Albums* > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& ptr_id (
          obj_traits::id (ptr_traits::get_ref (v)));

        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_image (
          i.album_id_value,
          is_null,
          ptr_id);
        i.album_id_null = is_null;
      }
      else
        i.album_id_null = true;
    }

    // genre_id_
    //
    {
      ::Genres* const& v =
        o.genre_id_;

      typedef object_traits< ::Genres > obj_traits;
      typedef odb::pointer_traits< ::Genres* > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& ptr_id (
          obj_traits::id (ptr_traits::get_ref (v)));

        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_image (
          i.genre_id_value,
          is_null,
          ptr_id);
        i.genre_id_null = is_null;
      }
      else
        i.genre_id_null = true;
    }

    // lyrics_
    //
    {
      ::std::string const& v =
        o.lyrics_;

      bool is_null (false);
      std::size_t cap (i.lyrics_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.lyrics_value,
        i.lyrics_size,
        is_null,
        v);
      i.lyrics_null = is_null;
      grew = grew || (cap != i.lyrics_value.capacity ());
    }

    // duration_
    //
    {
      double const& v =
        o.duration_;

      bool is_null (true);
      sqlite::value_traits<
          double,
          sqlite::id_real >::set_image (
        i.duration_value,
        is_null,
        v);
      i.duration_null = is_null;
    }

    // year_
    //
    {
      ::std::string const& v =
        o.year_;

      bool is_null (false);
      std::size_t cap (i.year_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.year_value,
        i.year_size,
        is_null,
        v);
      i.year_null = is_null;
      grew = grew || (cap != i.year_value.capacity ());
    }

    // file_location_
    //
    {
      ::std::string const& v =
        o.file_location_;

      bool is_null (false);
      std::size_t cap (i.file_location_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.file_location_value,
        i.file_location_size,
        is_null,
        v);
      i.file_location_null = is_null;
      grew = grew || (cap != i.file_location_value.capacity ());
    }

    // cover_art_
    //
    {
      ::std::vector< char > const& v =
        o.cover_art_;

      bool is_null (false);
      std::size_t cap (i.cover_art_value.capacity ());
      sqlite::value_traits<
          ::std::vector< char >,
          sqlite::id_blob >::set_image (
        i.cover_art_value,
        i.cover_art_size,
        is_null,
        v);
      i.cover_art_null = is_null;
      grew = grew || (cap != i.cover_art_value.capacity ());
    }

    // cover_art_size_
    //
    {
      int const& v =
        o.cover_art_size_;

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.cover_art_size_value,
        is_null,
        v);
      i.cover_art_size_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      int& v =
        o.id_;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.id_value,
        i.id_null);
    }

    // title_
    //
    {
      ::std::string& v =
        o.title_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.title_value,
        i.title_size,
        i.title_null);
    }

    // artist_id_
    //
    {
      ::Artists*& v =
        o.artist_id_;

      typedef object_traits< ::Artists > obj_traits;
      typedef odb::pointer_traits< ::Artists* > ptr_traits;

      if (i.artist_id_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type ptr_id;
        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_value (
          ptr_id,
          i.artist_id_value,
          i.artist_id_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<sqlite::database*> (db)->load<
            obj_traits::object_type > (ptr_id));
      }
    }

    // album_id_
    //
    {
      ::Albums*& v =
        o.album_id_;

      typedef object_traits< ::Albums > obj_traits;
      typedef odb::pointer_traits< ::Albums* > ptr_traits;

      if (i.album_id_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type ptr_id;
        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_value (
          ptr_id,
          i.album_id_value,
          i.album_id_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<sqlite::database*> (db)->load<
            obj_traits::object_type > (ptr_id));
      }
    }

    // genre_id_
    //
    {
      ::Genres*& v =
        o.genre_id_;

      typedef object_traits< ::Genres > obj_traits;
      typedef odb::pointer_traits< ::Genres* > ptr_traits;

      if (i.genre_id_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type ptr_id;
        sqlite::value_traits<
            obj_traits::id_type,
            sqlite::id_integer >::set_value (
          ptr_id,
          i.genre_id_value,
          i.genre_id_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<sqlite::database*> (db)->load<
            obj_traits::object_type > (ptr_id));
      }
    }

    // lyrics_
    //
    {
      ::std::string& v =
        o.lyrics_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.lyrics_value,
        i.lyrics_size,
        i.lyrics_null);
    }

    // duration_
    //
    {
      double& v =
        o.duration_;

      sqlite::value_traits<
          double,
          sqlite::id_real >::set_value (
        v,
        i.duration_value,
        i.duration_null);
    }

    // year_
    //
    {
      ::std::string& v =
        o.year_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.year_value,
        i.year_size,
        i.year_null);
    }

    // file_location_
    //
    {
      ::std::string& v =
        o.file_location_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.file_location_value,
        i.file_location_size,
        i.file_location_null);
    }

    // cover_art_
    //
    {
      ::std::vector< char >& v =
        o.cover_art_;

      sqlite::value_traits<
          ::std::vector< char >,
          sqlite::id_blob >::set_value (
        v,
        i.cover_art_value,
        i.cover_art_size,
        i.cover_art_null);
    }

    // cover_art_size_
    //
    {
      int& v =
        o.cover_art_size_;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.cover_art_size_value,
        i.cover_art_size_null);
    }
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::Track, id_sqlite >::persist_statement[] =
  "INSERT INTO \"Track\" "
  "(\"id\", "
  "\"title\", "
  "\"artist_id\", "
  "\"album_id\", "
  "\"genre_id\", "
  "\"lyrics\", "
  "\"duration\", "
  "\"year\", "
  "\"file_location\", "
  "\"cover_art\", "
  "\"cover_art_size\") "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::Track, id_sqlite >::find_statement[] =
  "SELECT "
  "\"Track\".\"id\", "
  "\"Track\".\"title\", "
  "\"Track\".\"artist_id\", "
  "\"Track\".\"album_id\", "
  "\"Track\".\"genre_id\", "
  "\"Track\".\"lyrics\", "
  "\"Track\".\"duration\", "
  "\"Track\".\"year\", "
  "\"Track\".\"file_location\", "
  "\"Track\".\"cover_art\", "
  "\"Track\".\"cover_art_size\" "
  "FROM \"Track\" "
  "WHERE \"Track\".\"id\"=?";

  const char access::object_traits_impl< ::Track, id_sqlite >::update_statement[] =
  "UPDATE \"Track\" "
  "SET "
  "\"title\"=?, "
  "\"artist_id\"=?, "
  "\"album_id\"=?, "
  "\"genre_id\"=?, "
  "\"lyrics\"=?, "
  "\"duration\"=?, "
  "\"year\"=?, "
  "\"file_location\"=?, "
  "\"cover_art\"=?, "
  "\"cover_art_size\"=? "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::Track, id_sqlite >::erase_statement[] =
  "DELETE FROM \"Track\" "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::Track, id_sqlite >::query_statement[] =
  "SELECT\n"
  "\"Track\".\"id\",\n"
  "\"Track\".\"title\",\n"
  "\"Track\".\"artist_id\",\n"
  "\"Track\".\"album_id\",\n"
  "\"Track\".\"genre_id\",\n"
  "\"Track\".\"lyrics\",\n"
  "\"Track\".\"duration\",\n"
  "\"Track\".\"year\",\n"
  "\"Track\".\"file_location\",\n"
  "\"Track\".\"cover_art\",\n"
  "\"Track\".\"cover_art_size\"\n"
  "FROM \"Track\"\n"
  "LEFT JOIN \"Artists\" AS \"artist_id\" ON \"artist_id\".\"id\"=\"Track\".\"artist_id\"\n"
  "LEFT JOIN \"Albums\" AS \"album_id\" ON \"album_id\".\"id\"=\"Track\".\"album_id\"\n"
  "LEFT JOIN \"Genres\" AS \"genre_id\" ON \"genre_id\".\"id\"=\"Track\".\"genre_id\"";

  const char access::object_traits_impl< ::Track, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"Track\"";

  const char access::object_traits_impl< ::Track, id_sqlite >::table_name[] =
  "\"Track\"";

  void access::object_traits_impl< ::Track, id_sqlite >::
  persist (database& db, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im.id_null = true;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.id_ = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;
    using sqlite::update_statement;

    callback (db, obj, callback_event::pre_update);

    sqlite::transaction& tr (sqlite::transaction::current ());
    sqlite::connection& conn (tr.connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& idi (sts.id_image ());
    init (idi, id (obj));

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::Track, id_sqlite >::
  erase (database& db, const id_type& id)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::Track, id_sqlite >::pointer_type
  access::object_traits_impl< ::Track, id_sqlite >::
  find (database& db, const id_type& id)
  {
    using namespace sqlite;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::Track, id_sqlite >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::Track, id_sqlite >::
  reload (database& db, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    const id_type& id (object_traits_impl::id (obj));
    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::Track, id_sqlite >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace sqlite;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::Track, id_sqlite >::object_type >
  access::object_traits_impl< ::Track, id_sqlite >::
  query (database& db, const query_base_type& q)
  {
    using namespace sqlite;
    using odb::details::shared;
    using odb::details::shared_ptr;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) sqlite::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::Track, id_sqlite >::
  erase_query (database& db, const query_base_type& q)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection (db));

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

namespace odb
{
  static bool
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          return true;
        }
        case 2:
        {
          db.execute ("DROP TABLE IF EXISTS \"Track\"");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"Track\" (\n"
                      "  \"id\" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\n"
                      "  \"title\" TEXT NOT NULL,\n"
                      "  \"artist_id\" INTEGER NULL,\n"
                      "  \"album_id\" INTEGER NULL,\n"
                      "  \"genre_id\" INTEGER NULL,\n"
                      "  \"lyrics\" TEXT NOT NULL,\n"
                      "  \"duration\" REAL NULL,\n"
                      "  \"year\" TEXT NOT NULL,\n"
                      "  \"file_location\" TEXT NOT NULL,\n"
                      "  \"cover_art\" BLOB NOT NULL,\n"
                      "  \"cover_art_size\" INTEGER NOT NULL,\n"
                      "  CONSTRAINT \"artist_id_fk\"\n"
                      "    FOREIGN KEY (\"artist_id\")\n"
                      "    REFERENCES \"Artists\" (\"id\")\n"
                      "    DEFERRABLE INITIALLY DEFERRED,\n"
                      "  CONSTRAINT \"album_id_fk\"\n"
                      "    FOREIGN KEY (\"album_id\")\n"
                      "    REFERENCES \"Albums\" (\"id\")\n"
                      "    DEFERRABLE INITIALLY DEFERRED,\n"
                      "  CONSTRAINT \"genre_id_fk\"\n"
                      "    FOREIGN KEY (\"genre_id\")\n"
                      "    REFERENCES \"Genres\" (\"id\")\n"
                      "    DEFERRABLE INITIALLY DEFERRED)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_sqlite,
    "",
    &create_schema);
}

#include <odb/post.hxx>
