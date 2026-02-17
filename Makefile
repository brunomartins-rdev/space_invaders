CC = gcc

INCLUDES = -Iinclude

RAYLIB_FLAGS = $(shell pkg-config --cflags --libs raylib)

ERROR_FLAGS = $(shell -Werror -Wall)

SRC = main.c $(wildcard src/**/*.c)

TARGET = game

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) $(INCLUDES) $(ERROR_FLAGS) -o $(TARGET) $(RAYLIB_FLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
