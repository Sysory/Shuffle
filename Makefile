.PHONY: all clean rebuild

CC= gcc
CFLAGS= -c -Wall -Werror -Wextra 

SOURCES= door_sort.c list.c list_tests.c

OBJECTS= $(SOURCES:.c=.o)

RESULT= ../build/
EXEC1= Quest_1
EXEC2= Quest_2

all:
	make door_struct; make list_test

door_struct: $(EXEC1)

list_test: $(EXEC2)

$(EXEC1): $(OBJECTS)
	$(CC) $(CFLAGS) dmanager_module.c -o dmanager_module.o
	$(CC) $^ dmanager_module.o -o $(RESULT)$(EXEC1)

$(EXEC2): $(OBJECTS)
	$(CC) $(CFLAGS) -D LIST_TEST dmanager_module.c -o dmanager_module.o
	$(CC) $^ dmanager_module.o -o $(RESULT)$(EXEC2)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

rebuild:
	make clean; make

clean:
	rm -rf ./*.o $(RESULT)Quest_*