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

SUB_TARGET = build/test_sub


sub:
	$(CC) $(CFLAGS) src/bigint_subtract.c tests/test_subtract.c -o $(SUB_TARGET)

run-sub: sub
	./$(SUB_TARGET)