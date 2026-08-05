CC = gcc
CFLAGS = -Wall -Wextra

TARGET = build/main

SRC = src/*.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)