CC = gcc
CFLAGS = -Wall -Wextra

TARGET = build/test

SRC = src/*.c
TEST = tests/test.c

all:
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)