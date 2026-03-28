DEFAULT_GOAL := chess
.PHONY : clean memorycheck memorycheckextreme

CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=gnu99 -g
MEM_CHECK_QUICK = valgrind
MEM_CHECK_EXTREME = valgrind -s --leak-check=full --show-leak-kinds=all

chess: chess.c
	$(CC) $^ $(CFLAGS) -o $@ 

memorycheck: chess
	$(MEM_CHECK_QUICK) ./$<

memorycheckextreme: chess
	$(MEM_CHECK_EXTREME) ./$<

clean:
	rm -f chess
	rm -rf chess.dSYM