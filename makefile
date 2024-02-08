C = gcc -g3
CFLAGS = -g3

all: Project0

Project0: main.o tree.o
        $(CC) $(CFLAGS) -o Project0 main.o tree.o

main.o: main.c node.h tree.h
        $(CC) $(CFLAGS) -c main.c

tree.o: tree.c node.h tree.h
        $(CC) $(CFLAGS) -c tree.c

clean:
        rm -f Project0 *.o
        rm -f output.PreOrder.txt
        rm -f output.InOrder.txt
        rm -f output.PostOrder.txt
        rm -f tempfile.txt
