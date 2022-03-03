.PHONY: all clean rebuild

CC= gcc
CFLAGS= -c -g -Wall -Werror -Wextra 
LDFLAGS= -g
RESULT= ../build/
EXEC= a.out

SOURCES= main.c array_math.c

OBJECTS= $(addprefix $(RESULT), $(SOURCES:.c=.o))

all: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $(RESULT)$(EXEC) -lm

$(RESULT)%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

rebuild:
	make clean --no-print-directory
	make --no-print-directory

clean:
	rm -rf $(RESULT)*