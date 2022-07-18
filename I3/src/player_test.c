/**
 * @brief It tests the player module
 *
 * @file player_test.c
 * @author Álexx
 * @version 2.0
 * @date 24-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/player.h"
#include "../include/player_test.h"
#include "../include/object.h"
#include "../include/inventory.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 30


/**
 * @brief Main function for PLAYER unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
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
        test1_player_create();
    if (all || test == 2)
        test2_player_create();
    if (all || test == 3)
        test3_player_create();
    if (all || test == 4)
        test1_player_set_id();
    if (all || test == 5)
        test2_player_set_id();
    if (all || test == 6)
        test1_player_set_name();
    if (all || test == 7)
        test2_player_set_name();
    if (all || test == 8)
        test1_player_set_location();
    if (all || test == 9)
        test2_player_set_location();
    if (all || test == 10)
        test1_player_set_inventory();
    if (all || test == 11)
        test2_player_set_inventory();
    if (all || test == 12)
        test1_player_add_object_inventory();
    if (all || test == 13)
        test2_player_add_object_inventory();
    if (all || test == 14)
        test1_player_del_object_inventory();
    if (all || test == 15)
        test2_player_del_object_inventory();
    if (all || test == 16)
        test1_player_get_objects_inventory();
    if (all || test == 17)
        test2_player_get_objects_inventory();
    if (all || test == 18)
        test1_player_id_in_inventory();
    if (all || test == 19)
        test2_player_id_in_inventory();
    if (all || test == 20)
        test3_player_id_in_inventory();
    if (all || test == 21)
        test1_player_inventory_is_full();
    if (all || test == 22)
        test2_player_inventory_is_full();
    if (all || test == 23)
        test3_player_inventory_is_full();
    if (all || test == 24)
        test1_player_set_health();
    if (all || test == 25)
        test2_player_set_health();
    if (all || test == 26)
        test1_player_get_id();
    if (all || test == 27)
        test1_player_get_name();
    if (all || test == 28)
        test1_player_get_location();
    if (all || test == 29)
        test1_player_get_inventory();
    if (all || test == 30)
        test1_player_get_health();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_player_create()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    PRINT_TEST_RESULT((p = player_create(10, "Rodrigo", 10, rinyo, 5)) != NULL);
    player_destroy(p);
}

void test2_player_create()
{
    Player *p = NULL;
    Inventory *rinyo = NULL;
    p = player_create(10, "Panda", 10, rinyo, 5);
    PRINT_TEST_RESULT(p == NULL);
    player_destroy(p);
}

void test3_player_create()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Panda", 10, rinyo, 5);
    PRINT_TEST_RESULT(player_get_id(p) == 10 && strcmp(player_get_name(p), "Panda") == 0 && player_get_location(p) == 10 && player_get_inventory(p) == rinyo && player_get_health(p) == 5);
    player_destroy(p);
}

void test1_player_set_id()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Juan", 10, rinyo, 5);
    player_set_id(p, 5);
    PRINT_TEST_RESULT(player_get_id(p) == 5);
    player_destroy(p);
}

void test2_player_set_id()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_id(p, 5) == ERROR);
}

void test1_player_set_name()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Cerda", 10, rinyo, 5);
    player_set_name(p, "Alex");
    PRINT_TEST_RESULT(strcmp(player_get_name(p), "Alex") == 0);
    player_destroy(p);
}

void test2_player_set_name()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_name(p, "Luca") == ERROR);
    player_destroy(p);
}

void test1_player_set_location()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Pedro", 10, rinyo, 5);
    player_set_location(p, 3);
    PRINT_TEST_RESULT(player_get_location(p) == 3);
    player_destroy(p);
}

void test2_player_set_location()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
}

void test1_player_set_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    Inventory *rinyo_buena = inventory_create(4);
    p = player_create(10, "Pedro", 10, rinyo, 5);
    PRINT_TEST_RESULT(player_set_inventory(p, rinyo_buena)==OK);
    inventory_destroy(rinyo);
    player_destroy(p);
}

void test2_player_set_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    Inventory *rinyo_mala = NULL;
    p = player_create(10, "Pedro", 10, rinyo, 5);
    PRINT_TEST_RESULT(player_set_inventory(p, rinyo_mala)==ERROR);
    player_destroy(p);
}

void test1_player_add_object_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Asier", 10, rinyo, 5);
    PRINT_TEST_RESULT(player_add_object_inventory(p, 8)==OK);
    player_destroy(p);
}

void test2_player_add_object_inventory()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_add_object_inventory(p, 8)==ERROR);
}

void test1_player_del_object_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Luca", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    PRINT_TEST_RESULT(player_del_object_inventory(p, 9)==OK);
    player_destroy(p);
}

void test2_player_del_object_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Johi", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    PRINT_TEST_RESULT(player_del_object_inventory(p, 8)==ERROR);
    player_destroy(p);
}

void test1_player_get_objects_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Kutxi", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    PRINT_TEST_RESULT(player_get_objects_inventory(p)!=NULL);
    player_destroy(p);
}

void test2_player_get_objects_inventory()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_objects_inventory(p)==NULL);
}

void test1_player_id_in_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Jimmy", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    PRINT_TEST_RESULT(player_id_in_inventory(p, 9)==TRUE || player_id_in_inventory(p, 8)==FALSE);
    player_destroy(p);
}

void test2_player_id_in_inventory()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(6);
    p = player_create(10, "Jimmy", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    PRINT_TEST_RESULT(player_id_in_inventory(p, NO_ID)==FALSE);
    player_destroy(p);
}

void test3_player_id_in_inventory()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_id_in_inventory(p, 9)==FALSE);
}

void test1_player_inventory_is_full()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(2);
    p = player_create(10, "Jimmy", 10, rinyo, 5);
    player_add_object_inventory(p, 9);
    player_add_object_inventory(p, 5);
    PRINT_TEST_RESULT(player_inventory_is_full(p)==TRUE);
    player_destroy(p);
}

void test2_player_inventory_is_full()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(2);
    p = player_create(10, "Jimmy", 10, rinyo, 5);
    PRINT_TEST_RESULT(player_inventory_is_full(p)==FALSE);
    player_destroy(p);
}

void test3_player_inventory_is_full()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_inventory_is_full(p)==FALSE);
    player_destroy(p);
}

void test1_player_set_health()
{
    Player *p = NULL;
    Inventory *rinyo = inventory_create(2);
    p = player_create(10, "Jimmy", 10, rinyo, 6);
    PRINT_TEST_RESULT(player_set_health(p, 3)==OK || player_get_health(p)==3);
    player_destroy(p);
}

void test2_player_set_health()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_health(p, 3)==ERROR);
}

void test1_player_get_id()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_id(p)==NO_ID);
}

void test1_player_get_name()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_name(p)==NULL);
}

void test1_player_get_location()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_location(p)==NO_ID);
}

void test1_player_get_inventory()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_inventory(p)==NULL);
}

void test1_player_get_health()
{
    Player *p = NULL;
    PRINT_TEST_RESULT(player_get_health(p)==-1);
}
