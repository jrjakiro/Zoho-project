/***********************************************************

This extension is built for counting number of 
        1.insert
        2.update
        3.delete
        4.select 
queries coming to a database. In this code we are particularly declaring a database named 'zoho' as the default database.

This extension only has its first version as far as now and it is relocatable.
The extension can be loaded by the command "CREATE EXTENSION calculate".
The control file named "calculate.control" contains the basic data about extension, sql file named "calculate--0.0.1.sql" ensures that these files are loaded only after creating extension and c file named "calculate--0.0.1.c" which contains the active code for the extension. These files should be placed inside the extension folder under shared directory.

calculate_test.sql file is used to test the code and the process is carried out smoothly by the Makefile.














***********************************************************/