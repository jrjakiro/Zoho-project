-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION count" to load this file. \quit
CREATE FUNCTION query_count()
RETURNS int
LANGUAGE plpgsql IMMUTABLE STRICT
  AS $$
    DECLARE
    val int;

    BEGIN
        val :=sum(xact_commit+xact_rollback) FROM pg_stat_database;

        RETURN(val);
    END;
  $$;