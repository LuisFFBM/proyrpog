CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

.PHONY: clean 

all: hormiguero clean

exec: hormiguero hormiguero.dat
	./hormiguero hormiguero.dat 

hormiguero: game_loop.o game.o game_reader.o  graphic_engine.o command.o space.o object.o player.o  
	$(CC) -o hormiguero game_loop.o game.o game_reader.o graphic_engine.o command.o space.o object.o player.o -L. -lscreen

game_loop.o: game_loop.c game.h graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

game.o: game.c game.h 
	$(CC) $(CFLAGS) -c game.c 

game_reader.o: game_reader.c game_reader.h 
	$(CC) $(CFLAGS) -c game_reader.c

graphic_engine.o: graphic_engine.c graphic_engine.h
	$(CC) $(CFLAGS) -c graphic_engine.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

space.o: space.c space.h
	$(CC) $(CFLAGS) -c space.c

object.o: object.c object.h
	$(CC) $(CFLAGS) -c object.c
	
player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c

clean:
	rm -f *.o 




		
