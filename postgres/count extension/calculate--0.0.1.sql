/* Use "CREATE EXTENSION calculate" to load this file

Initiating functions*/
CREATE FUNCTION count_insert()
RETURNS int
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

CREATE FUNCTION count_delete() 
RETURNS int
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

CREATE FUNCTION count_update()
RETURNS int
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

CREATE FUNCTION count_select()
RETURNS int
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

CREATE FUNCTION count_total()
RETURNS int 
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

CREATE FUNCTION clear_count() 
RETURNS int
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
