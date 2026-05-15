CC = gcc
TARGET = Game
SRC = main.c
CFLAGS = $(shell pkg-config --cflags raylib) -I./include
LIBS = $(shell pkg-config --libs raylib) -lGL -lm -lpthread -ldl -lrt -lX11

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
