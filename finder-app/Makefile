# Makefile for writer application

# Optional cross-compile prefix, e.g.:
#   make CROSS_COMPILE=aarch64-none-linux-gnu-
CROSS_COMPILE ?=

CC      := $(CROSS_COMPILE)gcc
CFLAGS  := -Wall -Werror -g

TARGET  := writer
SRC     := writer.c
OBJ     := $(SRC:.c=.o)

# Default target: build the writer application
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	rm -f $(TARGET) *.o
