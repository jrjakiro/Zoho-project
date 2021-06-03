#simple makefile to run the extension calculate
#PostgreSQL installation provides a build infrastructure for extensions, 
#called PGXS, so that simple extension modules can be built simply against an already installed server.



#extension name
EXTENSION = calculate
#our c module to build
MODULES = calculate--0.0.1
#script files to install
DATA = calculate--0.0.1.sql
#our test script file
REGRESS = calculate_test
#our object file
OBJS = calculate.o 
# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)