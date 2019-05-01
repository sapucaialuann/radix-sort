CC=gcc

all: queue.o radix.o main.o
	$(CC) queue.o radix.o main.o -o main.out

queue.o:
	$(CC) -c src/queue.c

radix.o: 
	$(CC) -c src/radix.c

main.o:
	$(CC) -c src/main.c

clean:
	rm *.out || true
	rm *.o || true
	rm *.obj || true