/**
 * @brief It tests the set module
 *
 * @file set_test.c
 * @author Álexx, Javii
 * @version 3.0
 * @date 13-03-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/set.h"
#include "../include/set_test.h"
#include "../include/types.h"
#include "../include/test.h"

#define MAX_TESTS 11

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Set:\n");
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
        test1_set_create();
    if (all || test == 2)
        test1_set_add();
    if (all || test == 3)
        test2_set_add();
    if (all || test == 4)
        test1_set_del();
    if (all || test == 5)
        test2_set_del();
    if (all || test == 6)
        test3_set_del();
    if (all || test == 7)
        test1_set_get_n_ids();
    if (all || test == 8)
        test1_set_get_ids();
    if (all || test == 9)
        test1_set_id_in_set();
    if (all || test == 10)
        test1_set_is_empty();
    if (all || test == 11)
        test2_set_is_empty();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_set_create()
{
    int result;
    Set *s = NULL;
    s = set_create();
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test1_set_add()
{
    int result;
    Set *s = NULL;
    Id id = 3;
    s = set_create();
    result = set_add(s, id) == OK;
    result = result && set_add(s, id) == ERROR;
    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test2_set_add()
{
    int result;
    result = set_add(NULL, 5) == ERROR;
    PRINT_TEST_RESULT(result);
}

void test1_set_del()
{
    Set *s = NULL;
    Id id = 3;
    s = set_create();
    set_add(s, id);
    PRINT_TEST_RESULT(set_del(s, id) == OK);
    set_destroy(s);
}

void test2_set_del()
{
    Set *s = NULL;
    PRINT_TEST_RESULT(set_del(NULL, 3) == ERROR);
    set_destroy(s);
}

void test3_set_del()
{
    Set *s = NULL;
    Id id = 3;
    s = set_create();
    set_add(s, id);
    PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
    set_destroy(s);
}

void test1_set_get_n_ids()
{
    int i = 0, nmovidas = 7;
    Set *s = NULL;
    s = set_create();
    for (i = 0; i < nmovidas; i++)
    {
        set_add(s, i);
    }

    PRINT_TEST_RESULT(set_get_n_ids(s) == nmovidas);
    set_destroy(s);
}

void test1_set_get_ids()
{
    int i = 0, nmovidas = 7, result = 1;
    Id *ids = NULL;
    Set *s = NULL;
    s = set_create();
    for (i = 0; i < nmovidas; i++)
    {
        result = result && set_add(s, i) == OK;
    }

    ids = set_get_ids(s);

    result = result && ids != NULL;

    for (i = 0; i < nmovidas; i++)
    {
        result = result && ids[i] == i;
    }

    PRINT_TEST_RESULT(result);
    /*free(ids);*/
    set_destroy(s);
}

void test1_set_id_in_set()
{
    int i = 0, nmovidas = 2, result = 1;
    Set *s = NULL;
    s = set_create();
    for (i = 0; i < nmovidas; i++)
    {
        result = result && set_add(s, i) == OK;
    }

    for (i = 0; i < nmovidas; i++)
    {
        result = result && set_id_in_set(s, i) == TRUE;
    }

    PRINT_TEST_RESULT(result);
    set_destroy(s);
}

void test1_set_is_empty()
{
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(set_is_empty(s));
    set_destroy(s);
}

void test2_set_is_empty()
{
    Set *s = NULL;
    s = set_create();
    set_add(s, 3);
    PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
    set_destroy(s);
}