
/**
 * @brief It tests the link module
 *
 * @file link_test.c
 * @author Luis
 * @version 3.0
 * @date 10-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/test.h"
#include "../include/link.h"
#include "../include/link_test.h"
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

    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();
    if (all || test == 3) test3_link_create();
    if (all || test == 4) test3_link_get_direction();
    if (all || test == 5) test1_link_destroy();
    if (all || test == 6) test2_link_destroy();
    if (all || test == 7) test1_link_get_id();
    if (all || test == 8) test2_link_get_id();
    if (all || test == 9) test1_link_set_name();
    if (all || test == 10) test2_link_set_name();
    if (all || test == 11) test3_link_set_name();
    if (all || test == 12) test1_link_get_name();
    if (all || test == 13) test3_link_get_name();
    if (all || test == 14) test3_link_get_name();
    if (all || test == 15) test1_link_set_status();
    if (all || test == 16) test2_link_set_status();
    if (all || test == 17) test3_link_set_status();
    if (all || test == 18) test4_link_set_status();
    if (all || test == 19) test1_link_get_status();
    if (all || test == 20) test2_link_get_status();
    if (all || test == 21) test3_link_get_status();
    if (all || test == 22) test1_link_set_origin();
    if (all || test == 23) test2_link_set_origin();
    if (all || test == 24) test3_link_set_origin();
    if (all || test == 25) test1_link_get_origin();
    if (all || test == 26) test2_link_get_origin();
    if (all || test == 27) test3_link_get_origin();
    if (all || test == 28) test1_link_set_destination();
    if (all || test == 29) test2_link_set_destination();
    if (all || test == 30) test3_link_set_destination();
    if (all || test == 31) test1_link_get_destination();
    if (all || test == 32) test2_link_get_destination();
    if (all || test == 33) test3_link_get_destination();
    if (all || test == 34) test1_link_set_direction();
    if (all || test == 35) test2_link_set_direction();
    if (all || test == 36) test3_link_set_direction();
    if (all || test == 37) test1_link_get_direction();
    if (all || test == 38) test2_link_get_direction(); 
        
    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_link_create()
{
    Link *l = NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_id(l) == 5);
    link_destroy(l);
}

void test2_link_create()
{
    Link *l = NULL;

    PRINT_TEST_RESULT((l = link_create(-1)) == NULL);
    link_destroy(l);
}

void test3_link_create()
{
    Link *l = NULL;

    PRINT_TEST_RESULT((l = link_create(NO_ID)) == NULL);
    link_destroy(l);
}

void test1_link_destroy()
{
    Link *l = NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_destroy(l) == OK);
}

void test2_link_destroy()
{
    Link *l = NULL;
    PRINT_TEST_RESULT(link_destroy(l) == ERROR);
}

void test1_link_get_id()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_id(l) == 5);
    link_destroy(l);
}

void test2_link_get_id()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

void test1_link_set_name()
{
    Link *l = NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_name(l,"link") == OK && strcmp(link_get_name(l), "link") == 0);
    link_destroy(l);
}


void test2_link_set_name()
{
    Link *l = NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_name(l,NULL ) == ERROR);
    link_destroy(l);
}

void test3_link_set_name()
{
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_name(l, "link") == ERROR);
}

void test1_link_get_name()
{
    Link *l= NULL;
    l = link_create(5);
    link_set_name(l, "link");
    PRINT_TEST_RESULT(strcmp(link_get_name(l), "link") == 0);
    link_destroy(l);
}

void test2_link_get_name()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_name(l) == NULL);
    link_destroy(l);
}

void test3_link_get_name()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

void test1_link_set_status()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_status(l,ERROR) == OK && link_get_status(l) == ERROR);
    link_destroy(l);

}

void test2_link_set_status()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_status(l,(-1)) == ERROR);
    link_destroy(l);

}

void test3_link_set_status()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_status(l,2) == ERROR);
    link_destroy(l);

}

void test4_link_set_status()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_set_status(l,ERROR) == ERROR);
}

void test1_link_get_status()
{
    Link *l= NULL;
    l = link_create(5);
    link_set_status(l,ERROR);
    PRINT_TEST_RESULT(link_get_status(l) == ERROR);
    link_destroy(l);
}

void test2_link_get_status()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_status(l) == ERROR);
    link_destroy(l);
}

void test3_link_get_status()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_status(l) == ERROR);
}

void test1_link_set_origin()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_origin(l,2) == OK && link_get_origin(l) == 2);
    link_destroy(l);
}

void test2_link_set_origin()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_origin(l,NO_ID) == ERROR);
    link_destroy(l);
}

void test3_link_set_origin()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_set_origin(l,2) == ERROR);
}

void test1_link_get_origin()
{
    Link *l= NULL;
    l = link_create(5);
    link_set_origin(l,2);
    PRINT_TEST_RESULT(link_get_origin(l) == 2);
    link_destroy(l);
}

void test2_link_get_origin()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_origin(l) == NO_ID);
    link_destroy(l);
}

void test3_link_get_origin()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_origin(l) == NO_ID);
}


void test1_link_set_destination()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_destination(l,2) == OK && link_get_destination(l) == 2);
    link_destroy(l);
}

void test2_link_set_destination()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_destination(l,NO_ID) == ERROR);
    link_destroy(l);
}

void test3_link_set_destination()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_set_destination(l,2) == ERROR);
}

void test1_link_get_destination()
{
    Link *l= NULL;
    l = link_create(5);
    link_set_destination(l,2);
    PRINT_TEST_RESULT(link_get_destination(l) == 2);
    link_destroy(l);
}

void test2_link_get_destination()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_destination(l) == NO_ID);
    link_destroy(l);
}

void test3_link_get_destination()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_destination(l) == NO_ID);
}

void test1_link_set_direction()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_direction(l,N) == OK && link_get_direction(l) == N);
    link_destroy(l);
}

void test2_link_set_direction()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_set_direction(l,NO_DIR) == ERROR);
    link_destroy(l);
}

void test3_link_set_direction()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_set_direction(l,N) == ERROR);
}

void test1_link_get_direction()
{
    Link *l= NULL;
    l = link_create(5);
    link_set_direction(l,S);
    PRINT_TEST_RESULT(link_get_direction(l) == S);
    link_destroy(l);
}


void test2_link_get_direction()
{
    Link *l= NULL;
    l = link_create(5);
    PRINT_TEST_RESULT(link_get_direction(l) == NO_DIR);
    link_destroy(l);
}

void test3_link_get_direction()
{
    Link *l= NULL;
    PRINT_TEST_RESULT(link_get_direction(l) == NO_DIR);
}



