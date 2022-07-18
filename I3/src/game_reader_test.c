#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/game_reader_test.h"
#include "../include/game.h"
#include "../include/game_reader.h"
#include "../include/space.h"
#include "../include/player.h"
#include "../include/link.h"
#include "../include/test.h"
#include "../include/inventory.h"
#include "../include/enemy.h"

#define MAX_TESTS 40

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module player:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) 
        test1_load_spaces();
    if (all || test == 2) 
        test2_load_spaces();
    if (all || test == 3) 
        test3_load_spaces();
    if (all || test == 4) 
        test1_load_object();
    if (all || test == 5) 
        test2_load_object();
    if (all || test == 6) 
        test3_load_object();
    if (all || test == 7) 
        test1_load_player();
    if (all || test == 8) 
        test2_load_player();
    if (all || test == 9) 
        test3_load_player();
    if (all || test == 10) 
        test1_load_link();
    if (all || test == 11) 
        test2_load_link();
    if (all || test == 12) 
        test3_load_link();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_load_spaces() {
    Game *game = game_create();
    FILE *fp = NULL;
    Space **spaces = NULL;

    fp = fopen("test.dat", "w");

    fprintf(fp, "#s:11|Entrada|  _____  | /     \\ |[       ]| \\     / |  \\   /  |");

    fclose(fp);

    game_reader_load_spaces(game, "test.dat");

    spaces = game_get_spaces(game);

    PRINT_TEST_RESULT(
        strcmp(space_get_name(spaces[0]), "Entrada") == 0 && 
        space_get_id(spaces[0]) == 11
    );
    game_destroy(game);
}

void test2_load_spaces() {
    Game *game = game_create();

    PRINT_TEST_RESULT(game_reader_load_spaces(game, "unexistingfile.dat") == ERROR);
    game_destroy(game);
}

void test3_load_spaces() {
    Game *game = game_create();
    FILE *fp = NULL;
    
    fp = fopen("test.dat", "w");
    
    fclose(fp);
    
    PRINT_TEST_RESULT(game_reader_load_spaces(NULL, "test.dat") == ERROR);
    game_destroy(game);
}

void test1_load_object() {
    Game *game = game_create();
    FILE *fp = NULL;
    Object **objects = NULL;

    fp = fopen("test.dat", "w");

    fprintf(fp, "#o:21|Grano|11");

    fclose(fp);

    game_reader_load_objects(game, "test.dat");

    objects = game_get_objects(game);

    PRINT_TEST_RESULT(strcmp(object_get_name(objects[0]), "Grano") == 0 && object_get_id(objects[0]) == 21);
    game_destroy(game);
}

void test2_load_object() {
    Game *game = game_create();

    PRINT_TEST_RESULT(game_reader_load_objects(game, "unexistingfile.dat") == ERROR);
    game_destroy(game);
}

void test3_load_object() {
    Game *game = game_create();
    FILE *fp = NULL;
    
    fp = fopen("test.dat", "w");
    
    fclose(fp);
    
    PRINT_TEST_RESULT(game_reader_load_objects(NULL, "test.dat") == ERROR);
    game_destroy(game);
}

void test1_load_player() {
    Game *game = game_create();
    FILE *fp = NULL;
    Player *player = NULL;

    fp = fopen("test.dat", "w");

    fprintf(fp, "#p:1|Vanessa|11|5|3|");

    fclose(fp);

    game_reader_load_player(game, "test.dat");

    player = game_get_player(game);

    PRINT_TEST_RESULT(strcmp(
        player_get_name(player), "Vanessa") == 0 && 
        player_get_id(player) == 1 &&
        player_get_location(player) == 11 &&
        player_get_health(player) == 5
    );
    
    game_destroy(game);
}

void test2_load_player() {
    Game *game = game_create();

    PRINT_TEST_RESULT(game_reader_load_player(game, "unexistingfile.dat") == ERROR);
    game_destroy(game);
}

void test3_load_player() {
    Game *game = game_create();
    FILE *fp = NULL;
    
    fp = fopen("test.dat", "w");
    
    fclose(fp);
    
    PRINT_TEST_RESULT(game_reader_load_player(NULL, "test.dat") == ERROR);
    game_destroy(game);
}

void test1_load_link() {
    Game *game = game_create();
    FILE *fp = NULL;
    Link **links = NULL;

    fp = fopen("test.dat", "w");

    fprintf(fp, "#l:31|Entrada|11|121|1|1|");

    fclose(fp);

    game_reader_load_link(game, "test.dat");

    links = game_get_links(game);

    PRINT_TEST_RESULT(
        link_get_id(links[0]) == 31 &&
        strcmp(link_get_name(links[0]), "Entrada") == 0 && 
        link_get_origin(links[0]) == 11 &&
        link_get_destination(links[0]) == 121 &&
        link_get_direction(links[0]) == 1 &&
        link_get_status(links[0]) == 1 
    );
    
    game_destroy(game);
}

void test2_load_link() {
    Game *game = game_create();

    PRINT_TEST_RESULT(game_reader_load_link(game, "unexistingfile.dat") == ERROR);
    game_destroy(game);
}

void test3_load_link() {
    Game *game = game_create();
    FILE *fp = NULL;
    
    fp = fopen("test.dat", "w");
    
    fclose(fp);
    
    PRINT_TEST_RESULT(game_reader_load_link(NULL, "test.dat") == ERROR);
    game_destroy(game);
}