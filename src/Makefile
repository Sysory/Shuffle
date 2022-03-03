.PHONY: all clean rebuild

CC= gcc
CFLAGS= -c -g -Wall -Werror -Wextra 
LDFLAGS= -g

SOURCES= main.c array_math.c

OBJECTS= $(RESULT)$(SOURCES:.c=.o)

RESULT= ../build/
EXEC= a.out

all: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $(RESULT)$(EXEC)

$(RESULT)%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

rebuild:
	make clean --no-print-directory
	make --no-print-directory

clean:
	rm -rf $(RESULT)*