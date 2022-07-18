CC	:= gcc
CCFLAGS	:= -Wall -pedantic -g -ansi

ARGS 	:= hormiguero.dat
EXE := juego
EXETESTS := enemy_test inventory_test player_test set_test space_test game_reader_test object_test link_test

VFLAGS	:= -s --leak-check=full --track-origins=yes

IFLAGS=-I./lib/
LDFLAGS=-L./lib/
LDLIBS=-lscreen

SRC-DIR:=./src
INCLUDE-DIR:=./include
OBJ-DIR:=./obj
LIB-DIR:=./lib
DOC-DIR:=./doc

SRCS := $(wildcard $(SRC-DIR)/*.c)
SRCNOTEST := $(filter-out $(wildcard $(SRC-DIR)/*_test.c), $(SRCS))
OBJSNOTEST:= $(SRCNOTEST:$(SRC-DIR)/%.c=$(OBJ-DIR)/%.o) 

TESTSSRCS := $(filter $(wildcard $(SRC-DIR)/*_test.c), $(SRCS))



$(EXE): $(OBJSNOTEST)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

enemy_test: $(OBJ-DIR)/enemy_test.o $(OBJ-DIR)/enemy.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

inventory_test: $(OBJ-DIR)/inventory_test.o $(OBJ-DIR)/inventory.o $(OBJ-DIR)/set.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

player_test: $(OBJ-DIR)/player_test.o $(OBJ-DIR)/player.o $(OBJ-DIR)/inventory.o $(OBJ-DIR)/object.o $(OBJ-DIR)/set.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

set_test: $(OBJ-DIR)/set_test.o $(OBJ-DIR)/set.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

space_test: $(OBJ-DIR)/space_test.o $(OBJ-DIR)/space.o $(OBJ-DIR)/set.o 
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

game_reader_test: $(OBJ-DIR)/game_reader_test.o $(OBJ-DIR)/game.o $(OBJ-DIR)/game_reader.o $(OBJ-DIR)/inventory.o $(OBJ-DIR)/link.o $(OBJ-DIR)/object.o $(OBJ-DIR)/player.o $(OBJ-DIR)/set.o $(OBJ-DIR)/space.o $(OBJ-DIR)/enemy.o $(OBJ-DIR)/command.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

object_test: $(OBJ-DIR)/object_test.o $(OBJ-DIR)/object.o 
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

link_test: $(OBJ-DIR)/link_test.o $(OBJ-DIR)/link.o 
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

command_test: $(OBJ-DIR)/command_test.o $(OBJ-DIR)/command.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS)

#####################################################
# .o tq<3 oli javi muxo animooo
#####################################################

$(OBJ-DIR):
	mkdir $(OBJ-DIR)

$(OBJ-DIR)/%.o: $(SRC-DIR)/%.c $(OBJ-DIR)
	$(CC) -c $(CCFLAGS) $< $(DEPFLAGS) -o $@

#####################################################
# function
#####################################################
.PHONY: all clear run valgrind doxygen documentacion

all: $(EXE) $(EXETEST)

clear: 
	rm -f $(OBJ-DIR)/*.o $(EXE) $(EXETESTS) test.dat

run: $(EXE)
	./$< $(ARGS)

valgrind: $(EXE)
	valgrind --log-file=valgrind.log $(VFLAGS) ./$< $(ARGS)

doxygen:
	doxygen Doxyfile

documentacion:
	doxygen Doxyfile