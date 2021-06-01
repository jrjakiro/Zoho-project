#simple makefile to run the extension calculate

#extension name
EXTENSION = calculate
#script files to install
DATA = calculate--0.0.1.sql
#our test script file
REGRESS = calculate_test
#our c module to build
MODULES = calculate
#our object file
OBJS = calculate.o 
# postgres build stuff
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
