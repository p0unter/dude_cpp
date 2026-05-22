CC = gcc
TARGET = App
SRC = main.c operations.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
