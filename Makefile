CC = gcc
CFLAGS = -Wall -Wextra

TARGET = build/test

SRC = src/bigint_add.c
TEST = tests/test_add.c


all:
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET)


run: all
	./$(TARGET)


clean:
	rm -f $(TARGET)
