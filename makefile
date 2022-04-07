programme: main.o daemon.o
	gcc -o programme main.o daemon.o

main.o: main.c
	gcc -c main.c

daemon.o: daemon.c
	gcc -c daemon.c

clean:
	rm *.o

build: programme clean

execute: programme clean
	./programme