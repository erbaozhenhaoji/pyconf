#
#
#
#
PLIB=..
INCLUDE = -I./ -I../src
LDFLAGS     = -L./ -L../src -lpyconf -lpthread -lm  -g
COMMON_DEFINES = -DLINUX -D_REENTERANT -Wall -D_FILE_OFFSET_BITS=64 $(INCLUDE)  -g

ifeq "$(MAKECMDGOALS)" "release"
	DEFINES=$(COMMON_DEFINES) -DNDEBUG -O3
	CPPFLAGS= $(DEFINES) 
else
	ifeq "$(MAKECMDGOALS)" "withpg"
		DEFINES=$(COMMON_DEFINES) 
		CPPFLAGS= -g -pg $(DEFINES) 
	else
		DEFINES=$(COMMON_DEFINES)
		CPPFLAGS= -g $(DEFINES) 
	endif
endif
CC  = gcc
AR  = ar
#=========================================================================

EXECUTABLE =  test_conf

TEST_EXEC = 

all	:  $(EXECUTABLE) $(LIBS) $(TEST_EXEC)

deps :
	$(CC) -MM -MG *.cpp >depends


test_conf : test_conf.o
	$(CC) -o $@ $^ $(LDFLAGS)

rebuild : clean all
clean   :
	/bin/rm -f *.o core.* *~ $(EXECUTABLE) $(TEST_EXEC) 


release : all
withpg  : all

-include depends

