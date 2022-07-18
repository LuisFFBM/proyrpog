/**
 * @brief It tests the enemy module
 *
 * @file enemy_test.c
 * @author Javii, Álexx
 * @version 3.0
 * @date 10-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/enemy.h"
#include "../include/enemy_test.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 10

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Enemy:\n");
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
        test1_enemy_create();
    if (all || test == 2)
        test2_enemy_create();
    if (all || test == 3)
        test1_enemy_set_id();
    if (all || test == 4)
        test2_enemy_set_id();
    if (all || test == 5)
        test1_enemy_set_name();
    if (all || test == 6)
        test2_enemy_set_name();
    if (all || test == 7)
        test1_enemy_set_location();
    if (all || test == 8)
        test2_enemy_set_location();
    if (all || test == 9)
        test1_enemy_set_health();
    if (all || test == 10)
        test2_enemy_set_health();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_enemy_create()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT((e = enemy_create(10, "Juan", 10, 5)) != NULL);
    enemy_destroy(e);
}

void test2_enemy_create()
{
    Enemy *e = NULL;
    e = enemy_create(10, "Juan", 10, 5);
    PRINT_TEST_RESULT(enemy_get_id(e) == 10 && strcmp(enemy_get_name(e), "Juan") == 0 && enemy_get_location(e) == 10 && enemy_get_health(e) == 5);
    enemy_destroy(e);
}

void test1_enemy_set_id()
{
    Enemy *e = NULL;
    e = enemy_create(10, "Juan", 10, 5);
    enemy_set_id(e, 5);
    PRINT_TEST_RESULT(enemy_get_id(e) == 5);
    enemy_destroy(e);
}

void test2_enemy_set_id()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_id(e, 5) == ERROR);
}

void test1_enemy_set_name()
{
    Enemy *e = NULL;
    e = enemy_create(10, "Juan", 10, 5);
    enemy_set_name(e, "Vane");
    PRINT_TEST_RESULT(strcmp(enemy_get_name(e), "Vane") == 0);
    enemy_destroy(e);
}

void test2_enemy_set_name()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_name(e, "Vane") == ERROR);
    enemy_destroy(e);
}

void test1_enemy_set_location()
{
    Enemy *e = NULL;
    e = enemy_create(10, "Juan", 10, 5);
    enemy_set_location(e, 3);
    PRINT_TEST_RESULT(enemy_get_location(e) == 3);
    enemy_destroy(e);
}

void test2_enemy_set_location()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_get_location(e) == NO_ID);
}

void test1_enemy_set_health()
{
    Enemy *e = NULL;
    e = enemy_create(10, "Juan", 10, 5);
    enemy_set_health(e, 3);
    PRINT_TEST_RESULT(enemy_get_health(e) == 3);
    enemy_destroy(e);
}

void test2_enemy_set_health()
{
    Enemy *e = NULL;
    PRINT_TEST_RESULT(enemy_set_health(e, 3) == ERROR);
}
