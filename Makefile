.PHONY: all clean rebuild

CC= gcc
CFLAGS= -c -g -Wall -Werror -Wextra 
LDFLAGS= -g

SOURCES= main.c

OBJECTS= $(SOURCES:.c=.o)

RESULT= ./build/
EXEC= a.out

all: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $(RESULT)$(EXEC)

%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

rebuild:
	make clean; make

clean:
	rm -rf ./*.o $(RESULT)*