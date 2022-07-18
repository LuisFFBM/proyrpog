/**
 * @brief It tests the inventory module
 *
 * @file inventory_test.c
 * @author Oskar
 * @version 3.0
 * @date 10-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/object.h"
#include "../include/inventory_test.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 17

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Inventory:\n");
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
            test1_inventory_create();
        if (all || test == 2)
            test2_inventory_create();
        if (all || test == 3)
            test1_inventory_destroy();
        if (all || test == 4)
            test2_inventory_destroy();
        if (all || test == 5)
            test1_inventory_is_full();
        if (all || test == 6)
            test2_inventory_is_full();
        if (all || test == 7)
            test1_inventory_add_object();
        if (all || test == 8)
            test2_inventory_add_object();
        if (all || test == 9)
            test1_inventory_remove_object();
        if (all || test == 10)
            test2_inventory_remove_object();
        if (all || test == 11)
            test1_inventory_get_objects();
        if (all || test == 12)
            test2_inventory_get_objects();
        if (all || test == 13)
            test3_inventory_get_objects();
        if (all || test == 14)
            test1_inventory_get_n_objs();
        if (all || test == 15)
            test2_inventory_get_n_objs();
        if (all || test == 16)
            test1_inventory_set_max_objs();
        if (all || test == 17)
            test2_inventory_set_max_objs();
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_inventory_create()
{
    Inventory *e = NULL;
    PRINT_TEST_RESULT((e = inventory_create(5)) != NULL);
    inventory_destroy(e);
}

void test2_inventory_create()
{
    Inventory *e = NULL;

    PRINT_TEST_RESULT((e = inventory_create(-3))==NULL);
         inventory_destroy(e);
}

void test1_inventory_destroy()
{
    Inventory *e = NULL;
    e = inventory_create(5);
    PRINT_TEST_RESULT(inventory_destroy(e) == OK);
}

void test2_inventory_destroy()
{
    Inventory *e = NULL;
    PRINT_TEST_RESULT(inventory_destroy(e) == ERROR);
}

void test1_inventory_is_full()
{
    Inventory *e = NULL;
    e = inventory_create(2);
    inventory_add_object(e,5);
    PRINT_TEST_RESULT(inventory_is_full(e) == FALSE);
    inventory_destroy(e);
}

void test2_inventory_is_full()
{
    Inventory *e = NULL;
    e = inventory_create(1);
    inventory_add_object(e,5);
    PRINT_TEST_RESULT(inventory_is_full(e) == TRUE);
    inventory_destroy(e);
}

void test1_inventory_add_object()
{
    Inventory *e = NULL;
    e = inventory_create(1);
    PRINT_TEST_RESULT(inventory_add_object(e, 1) == OK);
    inventory_destroy(e);
}

void test2_inventory_add_object()
{
    Inventory *e = NULL;
    e = inventory_create(1);
    PRINT_TEST_RESULT(inventory_add_object(e, NO_ID) == ERROR);
    inventory_destroy(e);
}

void test1_inventory_remove_object()
{
    Inventory *e = NULL;
    e = inventory_create(5);
    inventory_add_object(e,1);
    PRINT_TEST_RESULT(inventory_remove_object(e,1) == OK);
    inventory_destroy(e);
}

void test2_inventory_remove_object()
{
    Inventory *e = NULL;
    e = inventory_create(5);
    PRINT_TEST_RESULT(inventory_remove_object(e,1) == ERROR);
    inventory_destroy(e);
}



void test1_inventory_get_objects()
{
    Inventory *e = NULL;
     e = inventory_create(5);
    PRINT_TEST_RESULT(set_is_empty(inventory_get_objects(e)) == TRUE);
    inventory_destroy(e);
}

void test2_inventory_get_objects()
{
    Inventory *e = NULL;
     e = inventory_create(5);
     inventory_add_object(e,1);
    PRINT_TEST_RESULT(inventory_get_objects(e) != NULL);
    inventory_destroy(e);
}

void test3_inventory_get_objects()
{
    Inventory *e = NULL;
     e = inventory_create(5);
    PRINT_TEST_RESULT(set_get_n_ids(inventory_get_objects(e)) == 0);
    inventory_destroy(e);
}

void test1_inventory_get_n_objs()
{
    Inventory *e = NULL;
    e = inventory_create(5); 
    inventory_add_object(e,1);
    PRINT_TEST_RESULT(inventory_get_n_objs(e) == 1);
    inventory_destroy(e);
}

void test2_inventory_get_n_objs()
{
    Inventory *e = NULL;
    PRINT_TEST_RESULT(inventory_get_n_objs(e) == -1);
}

void test1_inventory_set_max_objs()
{
    Inventory *e = NULL;
    e = inventory_create(5); 
    PRINT_TEST_RESULT((inventory_set_max_objs(e, 0)) == ERROR);
    inventory_destroy(e);
}
void test2_inventory_set_max_objs()
{
    Inventory *e = NULL;
    e = inventory_create(5); 
    PRINT_TEST_RESULT((inventory_set_max_objs(e, 3)) == OK);
    inventory_destroy(e);
}