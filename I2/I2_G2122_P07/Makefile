CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
LFLAGS = -L. -lscreen

.PHONY: clean all exec test

all: hormiguero

exec: hormiguero hormiguero.dat
	valgrind --leak-check=full --show-leak-kinds=all -s ./hormiguero hormiguero.dat 

hormiguero: game_loop.o game.o game_reader.o  graphic_engine.o command.o space.o object.o player.o  enemy.o set.o libscreen.a
	$(CC) -o hormiguero game_loop.o game.o game_reader.o graphic_engine.o command.o space.o object.o player.o enemy.o set.o $(LFLAGS)

game_loop.o: game_loop.c graphic_engine.h
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

#I2 y los test
	


test: enemy_test space_test 
	
exec_enemy_test: enemy_test
	./enemy_test

exec_space_test: space_test
	./space_test

enemy_test: enemy_test.o enemy.o
	$(CC) -o enemy_test enemy_test.o enemy.o

enemy_test.o: enemy_test.c enemy_test.h enemy.h
	$(CC) $(CFLAGS) -c enemy_test.c
	
enemy.o: enemy.c enemy.h
	$(CC) $(CFLAGS) -c enemy.c

space_test: space_test.o space.o set.o
	$(CC) -o space_test space_test.o space.o set.o

set.o: set.c set.h
	$(CC) $(CFLAGS) -c set.c

clean:
	rm -f *.o 




		
