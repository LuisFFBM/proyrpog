/** 
 * @brief It tests enemy module
 * 
 * @file enemy_test.c
 * @author Profesores Pprog
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "enemy_test.h"

#define MAX_TESTS 16

/** 
 * @brief Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
      printf("Running all test for module Enemy:\n");
  } 
  else {
      test = atoi(argv[1]);
      all = 0;
      printf("Running test %d:\t", test);
      if (test < 1 && test > MAX_TESTS) {
          printf("Error: unknown test %d\t", test);
          exit(EXIT_SUCCESS);
      }
  }
  
  if (all || test == 1)  test1_enemy_get_id();
  if (all || test == 2)  test2_enemy_get_id();
  if (all || test == 3)  test1_enemy_get_name();
  if (all || test == 4)  test2_enemy_get_name();
  if (all || test == 5)  test1_enemy_set_name();
  if (all || test == 6)  test2_enemy_set_name();
  if (all || test == 7)  test3_enemy_set_name();
  if (all || test == 8)  test1_enemy_get_location();
  if (all || test == 9)  test2_enemy_get_location();
  if (all || test == 10)  test1_enemy_set_location();
  if (all || test == 12)  test2_enemy_set_location();
  if (all || test == 13)  test1_enemy_get_health();
  if (all || test == 14)  test2_enemy_get_health();
  if (all || test == 15)  test1_enemy_set_health();
  if (all || test == 16)  test2_enemy_set_health();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_enemy_create() {
  int result;
  Enemy *enem;
  enem = enemy_create(10);
  result=enem!=NULL ;
  PRINT_TEST_RESULT(result);
  enemy_destroy(enem);
}

void test2_enemy_create() {
  Enemy *enem;
  enem= enemy_create(10);
  PRINT_TEST_RESULT(enemy_get_id(enem) == 10);
  enemy_destroy(enem);
}

void test1_enemy_get_id() {
  Enemy *enem;
  enem = enemy_create(25);
  PRINT_TEST_RESULT(enemy_get_id(enem) == 25);
  enemy_destroy(enem);
}

void test2_enemy_get_id() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_get_id(enem) == NO_ID);
}

void test1_enemy_get_name() {
  Enemy *enem;
  enem = enemy_create(1);
  enemy_set_name(enem, "enemigo");
  PRINT_TEST_RESULT(strcmp(enemy_get_name(enem), "enemigo") == 0);
  enemy_destroy(enem);
}

void test2_enemy_get_name() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_get_name(enem) == NULL);
}

void test1_enemy_set_name() {
  Enemy *enem;
  enem = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(enem, "enemy") == OK);
  enemy_destroy(enem);
}

void test2_enemy_set_name() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_set_name(enem, "enemy") == ERROR);
}

void test3_enemy_set_name() {
  Enemy *enem;
  enem = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_name(enem, NULL) == ERROR);
  enemy_destroy(enem);
}

void test1_enemy_get_location() {
  Enemy *enem;
  enem = enemy_create(10);
  enemy_set_location(enem, 20);
  PRINT_TEST_RESULT(enemy_get_location(enem) == 20);
  enemy_destroy(enem);
}

void test2_enemy_get_location() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_get_location(enem) == NO_ID);
}

void test1_enemy_set_location() {
  Enemy *enem;
  enem = enemy_create(20);
  PRINT_TEST_RESULT(enemy_set_location(enem, 10) == OK);
  enemy_destroy(enem);
}

void test2_enemy_set_location() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_set_location(enem, 10) == ERROR);
}

void test1_enemy_get_health() {
  Enemy *enem;
  enem = enemy_create(30);
  enemy_set_health(enem, 100);
  PRINT_TEST_RESULT(enemy_get_health(enem) == 100);
  enemy_destroy(enem);
}

void test2_enemy_get_health() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_get_health(enem) == NO_ID);
}

void test1_enemy_set_health() {
  Enemy *enem;
  enem = enemy_create(5);
  PRINT_TEST_RESULT(enemy_set_health(enem, 30) == OK);
  enemy_destroy(enem);
}

void test2_enemy_set_health() {
  Enemy *enem = NULL;
  PRINT_TEST_RESULT(enemy_set_health(enem, 30) == ERROR);
}
