SOURCES         := $(wildcard *.c)
CC				:= gcc
EXECUTABLE      := main 

BASENAMES       = $(basename $(SOURCES))
OBJECTS         = $(addsuffix .o,$(BASENAMES))
CC_CFLAGS         = -std=c99

$(EXECUTABLE):  $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(GLOBAL_LIBSS)

%.o:	%.c
	$(CC)  -c $(CC_CFLAGS) $<

.PHONY: clean
clean:
	-rm  --force  $(EXECUTABLE) $(OBJECTS) *~

