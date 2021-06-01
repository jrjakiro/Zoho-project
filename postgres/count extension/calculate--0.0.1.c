//C program extension to count number of insert, delete, update, select queries Executed

//including required header files
#pragma once
#include <stdio.h>
//for basic postgres elements
#include "postgres.h"
//for using macros
#include "fmgr.h"
//for using basic elements and datatypes
#include "utils/builtins.h"

//for pg
PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(count_insert); 
PG_FUNCTION_INFO_V1(count_delete); 
PG_FUNCTION_INFO_V1(count_update); 
PG_FUNCTION_INFO_V1(count_select); 
PG_FUNCTION_INFO_V1(count_total);
PG_FUNCTION_INFO_V1(clear_count); 

//code to be executed during loading and unloading of extension
void _PG_init(void)
{
    //considering for default database
    char db[10] = 'zoho';
    //C code here at time of extension loading
    int count_insert();
    int count_delete();
    int count_update();
    int count_select();
    int count_total();
    int clear_count();
}
void _PG_fini(void)
{
    //C code here at time of extension unloading
}
//can be of anydatatype to return
//since we assigned default database the args is empty
Datum
count_insert(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text((postgresql.query.time.disk_read{query : 'insert', database : db, user : 'postgres', instance : 'Y', source_hostname : 'localhost'})));
}
Datum
count_delete(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text((postgresql.query.time.disk_read{query : 'delete', database : db, user : 'postgres', instance : 'Y', source_hostname : 'localhost'})));
}
Datum
count_update(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text((postgresql.query.time.disk_read{query : 'update', database : db, user : 'postgres', instance : 'Y', source_hostname : 'localhost'})));
}
Datum
count_select(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text((postgresql.query.time.disk_read{query : 'select', database : db, user : 'postgres', instance : 'Y', source_hostname : 'localhost'})));
}
Datum
count_total(PG_FUNCTION_ARGS)
{
    PG_RETURN_TEXT_P(cstring_to_text((postgresql.query.time.disk_read{ database : db, user : 'postgres', instance : 'Y', source_hostname : 'localhost'})));
}
Datum
count_clear(PG_FUNCTION_ARGS)
{
    delete ('$libdir/log');
}