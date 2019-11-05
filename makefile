ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o LinkList.o SongLibrary.o
	$(CC) -o playlist main.o LinkList.o SongLibrary.o

main.o: main.c LinkList.h SongLibrary.h
	$(CC) -c main.c

SongLibrary.o: SongLibrary.c SongLibrary.h LinkList.h
	$(CC) -c SongLibrary.c

LinkList.o: LinkList.c LinkList.h
	$(CC) -c LinkList.c


run: 
	./playlist

clean:
	rm *.o
	rm *~
