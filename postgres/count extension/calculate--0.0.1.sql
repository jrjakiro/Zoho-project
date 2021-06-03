-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION calculate" to load this file.\quit

--creating the total count & returns as text inorder to prevent accidental modification of data
CREATE FUNCTION count_total()
RETURNS TEXT 
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
--increments the total value
CREATE FUNCTION add_total()
RETURNS NULL
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;




--creating the insert functions 
CREATE FUNCTION count_insert()
RETURNS TEXT
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
CREATE FUNCTION add_insert()
RETURNS NULL
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;

--creating a trigger when insert command is executed
CREATE TRIGGERINSERT 
AFTER INSERT FOR EACH STATEMENT 
EXECUTE PROCEDURE add_insert(); 


--creating delete functions
CREATE FUNCTION count_delete() 
RETURNS TEXT
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
CREATE FUNCTION add_delete()
RETURNS NULL
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;


--creating a trigger when delete command is executed
CREATE TRIGGERDELETE 
AFTER DELETE FOR EACH STATEMENT 
EXECUTE PROCEDURE add_delete(); 



--creating update functions
CREATE FUNCTION count_update() 
RETURNS TEXT
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
CREATE FUNCTION add_update()
RETURNS NULL
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;


--creating a trigger when update command is executed
CREATE TRIGGERUPDATE 
AFTER UPDATE FOR EACH STATEMENT
EXECUTE PROCEDURE add_update(); 



--creating select functions
CREATE FUNCTION count_select() 
RETURNS TEXT
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
CREATE FUNCTION add_select()
RETURNS NULL
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;


--creating a trigger when select command is executed
CREATE TRIGGERSELECT 
AFTER SELECT FOR EACH STATEMENT 
EXECUTE PROCEDURE add_select(); 




--creating clear function
CREATE FUNCTION clear_count() 
RETURNS TEXT
AS '$libdir/calculate'
LANGUAGE C STRICT VOLATILE;
