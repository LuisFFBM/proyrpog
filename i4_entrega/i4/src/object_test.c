    /**
 * @file object_test.c
 * @author oskar
 * @brief it tests the object module
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/object.h"
#include "../include/object_test.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 14

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module object:\n");
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
        test1_object_create();
    if (all || test == 2)
        test2_object_create();
    if (all || test == 3)
        test1_object_get_description();
    if (all || test == 4)
        test2_object_get_description();
    if (all || test == 5)
        test1_object_set_name();
    if (all || test == 6)
        test2_object_set_name();
    if (all || test == 7)
        test1_object_set_id();
    if (all || test == 8)
        test2_object_set_id();
    if (all || test == 9)
        test1_object_get_name();
    if (all || test == 10)
        test2_object_get_name();
    if (all || test == 11)
        test1_object_get_id();
    if (all || test == 12)
        test2_object_get_id();
    if (all || test == 13)
        test1_object_set_description();
    if (all || test == 14)
        test2_object_set_description();

    PRINT_PASSED_PERCENTAGE; 
    return 1;
    }


void test1_object_create()
{
    Object *o = NULL;
    PRINT_TEST_RESULT((o = object_create(10, "IanCurtis")) != NULL);
    object_destroy(o);
}
void test2_object_create()
{
    Object *o = NULL;
    o = object_create(10, "AliceGlass");
    PRINT_TEST_RESULT(object_get_id(o) == 10 && strcmp(object_get_name(o), "AliceGlass") == 0);
    object_destroy(o);
}


void test1_object_set_name()
{
    Object *o = NULL;
    o = object_create(10, "Juan");
    object_set_name(o, "Albany");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "Albany") == 0);
    object_destroy(o);
}

void test2_object_set_name()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_name(o, "SotoAsa") == ERROR);
    object_destroy(o); 
}

void test1_object_set_id()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_id(o, 5) == ERROR);
}

void test2_object_set_id()
{
    Object *o = NULL;
    o = object_create(10, "Morrisey");
    object_set_id(o, 5);
    PRINT_TEST_RESULT(object_get_id(o) == 5);
    object_destroy(o);
}
void test1_object_get_name()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_name(o)==NULL);
}

void test2_object_get_name()
{
    Object *o = NULL;
    o = object_create(10, "Yolandi");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "Yolandi") == 0);
}

void test1_object_get_id()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_id(o)==NO_ID);
}

void test2_object_get_id()
{
    Object *o = NULL;
    o = object_create(10, "Xenia");
    PRINT_TEST_RESULT(object_get_id(o)==10);
}

void test1_object_set_description()
{
    Object *o = NULL;
    o = object_create(10, "Valdivia");
    object_set_description(o,"buena");
    PRINT_TEST_RESULT(strcmp(object_get_description(o), "buena") == 0);
    object_destroy(o);
}

void test2_object_set_description()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_description(o,"perprriori") == ERROR);
}
void test1_object_get_description()
{
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_description(o)==NULL);
}
void test2_object_get_description()
{
    Object *o = NULL;
    o = object_create(10, "Grimes");
    object_set_description(o,"peerrrororororor");
    PRINT_TEST_RESULT(strcmp(object_get_description(o), "peerrrororororor")==0);
}

