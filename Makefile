SRC = main.c
C = gcc
CFLAGS = -Wall -Wextra -g
BIN = queue.exe
RM = del

clean:
	$(RM) $(BIN)

all:
	$(C) $(CFLAGS) $(SRC) -o $(BIN)