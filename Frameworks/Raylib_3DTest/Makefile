CC = gcc
TARGET = Game
SRC = main.c
CFLAGS = $(shelll pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib) 

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CLAGS) $(LIBS)

.PHONY: all clean
