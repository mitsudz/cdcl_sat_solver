.DEFAULT_GOAL := all
.PHONY : clean memorycheck memorycheckextreme

CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c11 -g
TARGET = solver
OBJ = main.o cnf.o

MEM_CHECK_QUICK = valgrind
MEM_CHECK_EXTREME = valgrind -s --leak-check=full --show-leak-kinds=all

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c cnf.h
	$(CC) $(CFLAGS) -c main.c

cnf.o: cnf.c cnf.h
	$(CC) $(CFLAGS) -c cnf.c

memorycheck: $(TARGET)
	$(MEM_CHECK_QUICK) ./$(TARGET)

memorycheckextreme: $(TARGET)
	$(MEM_CHECK_EXTREME) ./$(TARGET)

clean:
	rm -f *.o $(TARGET)
