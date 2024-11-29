CC = gcc
CFLAGS = -g -Wall
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = a.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	del /q $(OBJ) $(TARGET)
