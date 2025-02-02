all: main

OBJS = main.o helpers.o rod_cutting.o error_handling.o
CC = clang
CFLAGS = -g -Wall

main: $(OBJS)
	clang -o main $(CFLAGS) $(OBJS)

main.o: main.c rod_cutting.h helpers.h error_handling.h

helpers.o: helpers.c error_handling.h

rod_cutting.o: rod_cutting.c

error_handling.o: error_handling.c

clean:
	rm -f main $(OBJS)
