CC = gcc
TARGET = Game
SRC = main.c utils.c 
CFLAGS = $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean

