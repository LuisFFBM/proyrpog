#include <stdio.h>
#include "../include/game_test.h"
#include "../include/game.h"
#include "../include/space.h"
#include "../include/test.h"
#include "../include/enemy.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 39

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Link:\n");
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

    if (all || test == 1)  test1_game_create();
    if (all || test == 2)  test1_game_add_space();
    if (all || test == 3)  test2_game_add_space();
    if (all || test == 4)  test3_game_add_space();
    if (all || test == 5)  test1_game_player_add_space();
    if (all || test == 6)  test2_game_player_add_space();
    if (all || test == 7)  test3_game_player_add_space();
    if (all || test == 8)  test1_game_enemy_add_space();
    if (all || test == 9)  test2_game_enemy_add_space();
    if (all || test == 10) test3_game_enemy_add_space(); 
    if (all || test == 11) test1_game_get_space(); 
    if (all || test == 12) test1_game_get_player(); 
    if (all || test == 13) test2_game_get_player(); 
    if (all || test == 14) test1_game_get_enemy(); 
    if (all || test == 15) test2_game_get_enemy(); 
        
    PRINT_PASSED_PERCENTAGE;

    return 1;
}
 
void test1_game_create() {
    Game * g = game_create();

    PRINT_TEST_RESULT(g != NULL);

    game_destroy(g);
}

void test1_game_add_space() {
    Game * g = game_create();
    Space *s = space_create(1);

    PRINT_TEST_RESULT(game_add_space(g, s) == OK);

    game_destroy(g);
}

void test2_game_add_space() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_add_space(g, NULL) == ERROR);

    game_destroy(g);
}

void test3_game_add_space() {
    Space *s = space_create(1);

    PRINT_TEST_RESULT(game_add_space(NULL, s) == ERROR);

    space_destroy(s);
}

void test1_game_player_add_space() {
    Game * g = game_create();
    Inventory *i = inventory_create(3);
    Player *p = player_create(1, "Juan", 1, i ,1);

    PRINT_TEST_RESULT(game_add_player(g, p) == OK);

    game_destroy(g);
}

void test2_game_player_add_space() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_add_player(g, NULL) == ERROR);

    game_destroy(g);
}

void test3_game_player_add_space() {
    Player *p = player_create(1, "Juan", 1, NULL ,1);

    PRINT_TEST_RESULT(game_add_player(NULL, p) == ERROR);

    player_destroy(p);
}

void test1_game_enemy_add_space() {
    Game * g = game_create();
    Enemy *e = enemy_create(1, "Juan", 1 ,1);

    PRINT_TEST_RESULT(game_add_enemy(g, e) == OK);

    game_destroy(g);
}

void test2_game_enemy_add_space() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_add_enemy(g, NULL) == ERROR);

    game_destroy(g);
}

void test3_game_enemy_add_space() {
    Enemy *e = enemy_create(1, "Juan", 1 ,1);

    PRINT_TEST_RESULT(game_add_enemy(NULL, e) == ERROR);

    enemy_destroy(e);
}

void test1_game_get_space() {
    Game * g = game_create();
    Space *s = space_create(1);

    game_add_space(g, s);

    PRINT_TEST_RESULT(game_get_space(g, 1) != NULL);

    game_destroy(g);
}

void test2_game_get_space() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_get_space(g, 1) == NULL);

    game_destroy(g);
}

void test1_game_get_player() {
    Game * g = game_create();
    Player *p = player_create(1, "a", 1, NULL, 1);

    game_add_player(g, p);

    PRINT_TEST_RESULT(game_get_player(g) != NULL);

    game_destroy(g);
}

void test2_game_get_player() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_get_player(g) == NULL);

    game_destroy(g);
}

void test1_game_get_enemy() {
    Game * g = game_create();
    Enemy *e = enemy_create(1, "a", 1, 1);

    game_add_enemy(g, e);

    PRINT_TEST_RESULT(game_get_enemy(g) != NULL);

    game_destroy(g);
}

void test2_game_get_enemy() {
    Game * g = game_create();

    PRINT_TEST_RESULT(game_get_enemy(g) == NULL);

    game_destroy(g);
}

