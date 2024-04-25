// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "Roles-odb.hxx"

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
  // Roles
  //

  struct access::object_traits_impl< ::Roles, id_sqlite >::extra_statement_cache_type
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

  access::object_traits_impl< ::Roles, id_sqlite >::id_type
  access::object_traits_impl< ::Roles, id_sqlite >::
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

  access::object_traits_impl< ::Roles, id_sqlite >::id_type
  access::object_traits_impl< ::Roles, id_sqlite >::
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

  bool access::object_traits_impl< ::Roles, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id
    //
    t[0UL] = false;

    // name
    //
    if (t[1UL])
    {
      i.name_value.capacity (i.name_size);
      grew = true;
    }

    return grew;
  }

  void access::object_traits_impl< ::Roles, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // id
    //
    if (sk != statement_update)
    {
      b[n].type = sqlite::bind::integer;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // name
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.name_value.data ();
    b[n].size = &i.name_size;
    b[n].capacity = i.name_value.capacity ();
    b[n].is_null = &i.name_null;
    n++;
  }

  void access::object_traits_impl< ::Roles, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::Roles, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // id
    //
    if (sk == statement_insert)
    {
      int const& v =
        o.id;

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        v);
      i.id_null = is_null;
    }

    // name
    //
    {
      ::std::string const& v =
        o.name;

      bool is_null (false);
      std::size_t cap (i.name_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.name_value,
        i.name_size,
        is_null,
        v);
      i.name_null = is_null;
      grew = grew || (cap != i.name_value.capacity ());
    }

    return grew;
  }

  void access::object_traits_impl< ::Roles, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id
    //
    {
      int& v =
        o.id;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.id_value,
        i.id_null);
    }

    // name
    //
    {
      ::std::string& v =
        o.name;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.name_value,
        i.name_size,
        i.name_null);
    }
  }

  void access::object_traits_impl< ::Roles, id_sqlite >::
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

  const char access::object_traits_impl< ::Roles, id_sqlite >::persist_statement[] =
  "INSERT INTO \"Roles\" "
  "(\"id\", "
  "\"name\") "
  "VALUES "
  "(?, ?)";

  const char access::object_traits_impl< ::Roles, id_sqlite >::find_statement[] =
  "SELECT "
  "\"Roles\".\"id\", "
  "\"Roles\".\"name\" "
  "FROM \"Roles\" "
  "WHERE \"Roles\".\"id\"=?";

  const char access::object_traits_impl< ::Roles, id_sqlite >::update_statement[] =
  "UPDATE \"Roles\" "
  "SET "
  "\"name\"=? "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::Roles, id_sqlite >::erase_statement[] =
  "DELETE FROM \"Roles\" "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::Roles, id_sqlite >::query_statement[] =
  "SELECT "
  "\"Roles\".\"id\", "
  "\"Roles\".\"name\" "
  "FROM \"Roles\"";

  const char access::object_traits_impl< ::Roles, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"Roles\"";

  const char access::object_traits_impl< ::Roles, id_sqlite >::table_name[] =
  "\"Roles\"";

  void access::object_traits_impl< ::Roles, id_sqlite >::
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

    obj.id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::Roles, id_sqlite >::
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

  void access::object_traits_impl< ::Roles, id_sqlite >::
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

  access::object_traits_impl< ::Roles, id_sqlite >::pointer_type
  access::object_traits_impl< ::Roles, id_sqlite >::
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

  bool access::object_traits_impl< ::Roles, id_sqlite >::
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

  bool access::object_traits_impl< ::Roles, id_sqlite >::
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

  bool access::object_traits_impl< ::Roles, id_sqlite >::
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

  result< access::object_traits_impl< ::Roles, id_sqlite >::object_type >
  access::object_traits_impl< ::Roles, id_sqlite >::
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
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) sqlite::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::Roles, id_sqlite >::
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
          db.execute ("DROP TABLE IF EXISTS \"Roles\"");
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
          db.execute ("CREATE TABLE \"Roles\" (\n"
                      "  \"id\" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\n"
                      "  \"name\" TEXT NOT NULL)");
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
