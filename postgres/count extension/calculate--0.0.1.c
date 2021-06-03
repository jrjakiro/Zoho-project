//C program extension to count number of insert, delete, update, select queries Executed
//these functions are dynamically loaded by the server using shared library into which the package is built
//including required header files
//for basic postgres elements
#include "postgres.h"
//for the basic c elements
#include <stdio.h>
#include <string.h>
//for using macros
#include "fmgr.h"
//for using basic elements and datatypes
#include "utils/builtins.h"

//for includinga magic block
PG_MODULE_MAGIC;
#ifndef(total_count)
{
    //declaring count variables with size of 1 byte has a range of 0 to 255
    unsigned int8 insert_count = 0;
    unsigned int8 delete_count = 0;
    unsigned int8 update_count = 0;
    unsigned int8 select_count = 0;
    unsigned int8 total_count = 0;
    //considering for database
    char db[10] = 'zoho';
}

//can be of anydatatype to return
//since we assigned default database the args is empty
//for returning and incrementing total value
PG_FUNCTION_INFO_V1(count_total);
Datum
    count_total(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(total_count);
}
PG_FUNCTION_INFO_V1(add_total);
Datum
    add_total(PG_FUNCTION_ARGS)
{
    total_count++;
}

//for insert query
PG_FUNCTION_INFO_V1(add_insert);
Datum
    count_insert(PG_FUNCTION_ARGS)
{
    //for incrementing the total count
    add_total();
    insert_count++;
}
//for returning the count of insert
PG_FUNCTION_INFO_V1(count_insert);
Datum
    count_insert(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(insert_count);
}

//for delete query
PG_FUNCTION_INFO_V1(add_delete);
Datum
    count_delete(PG_FUNCTION_ARGS)
{
    //for incrementing the total count
    add_total();
    delete_count++;
}
//for returning the count of delete
PG_FUNCTION_INFO_V1(count_delete);
Datum
    count_delete(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(delete_count);
}

//for update query
PG_FUNCTION_INFO_V1(add_update);
Datum
    count_update(PG_FUNCTION_ARGS)
{
    //for incrementing the total count
    add_total();
    update_count++;
}
//for returning the count of update
PG_FUNCTION_INFO_V1(count_update);
Datum
    count_update(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(update_count);
}

//for select query
PG_FUNCTION_INFO_V1(add_select);
Datum
    count_select(PG_FUNCTION_ARGS)
{
    //for incrementing the select count
    add_total();
    select_count++;
}
//for returning the count of select
PG_FUNCTION_INFO_V1(count_select);
Datum
    count_select(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(select_count);
}

//for clearing all the count
PG_FUNCTION_INFO_V1(clear_count);
Datum
    clear_count(PG_FUNCTION_ARGS)
{
    insert_count = 0;
    delete_count = 0;
    update_count = 0;
    select_count = 0;
    total_count = 0;

    PG_RETURN_TEXT_P("Count is cleared");
}
