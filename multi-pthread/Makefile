SOURCES         := $(wildcard *.c)
CC				:= gcc
EXECUTABLE      := multi-pthread

BASENAMES       = $(basename $(SOURCES))
OBJECTS         = $(addsuffix .o,$(BASENAMES))
GLOBAL_LIBSS 	= -lpthread

$(EXECUTABLE):  $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(GLOBAL_LIBSS)

.PHONY: clean

clean:
	-rm  --force  $(EXECUTABLE) $(OBJECTS) *~

