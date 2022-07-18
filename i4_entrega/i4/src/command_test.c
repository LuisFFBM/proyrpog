/** 
 * @brief It tests the command module
 * 
 * @file command_test.c
 * @author Joaquin Abad
 * @version 0.1
 * @date 24-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/command.h"
#include "../include/command_test.h"
#include "../include/test.h"
#include "../include/types.h"

#define MAX_TESTS 14


int main(int argc, char** argv)
{

  int test = 0;
  int all = 1;

  if (argc < 2)
  {
    printf("Running all test for module command:\n");
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
    test1_command_create();
  if (all || test == 2)
    test1_command_set_cmd();
  if (all || test == 3)
    test2_command_set_cmd();
  if (all || test == 4)
    test1_command_get_cmd();
  if (all || test == 5)
    test2_command_get_cmd();
  if (all || test == 6)
    test1_command_set_input();
  if (all || test == 7)
    test2_command_set_input();
  if (all || test == 8)
    test3_command_set_input();
  if (all || test == 9)
    test1_command_get_input();
  if (all || test == 10)
    test2_command_get_input();
  if (all || test == 11)
    test1_command_set_status();
  if (all || test == 12)
    test2_command_set_status();
  if (all || test == 13)
    test1_command_get_status();
  if (all || test == 14)
    test2_command_get_status();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_command_create()
{
  Command *command = NULL;
  command = command_create();
  PRINT_TEST_RESULT(command!=NULL);
  command_destroy(command);
}

void test1_command_set_status()
{
  Command *command = NULL;
  command = command_create();
  PRINT_TEST_RESULT(command_set_status(command, OK));
  command_destroy(command);
}

void test2_command_set_status()
{
  Command *command = NULL;
  PRINT_TEST_RESULT(command_set_status(command, OK)==ERROR);
}

void test1_command_get_status()
{
  Command *command = NULL;
  command = command_create();
  command_set_status(command, OK);
  PRINT_TEST_RESULT(command_get_status(command)==OK);
  command_destroy(command);
}

void test2_command_get_status()
{
  Command *command = NULL;
  command = command_create();
  command_set_status(command, ERROR);
  PRINT_TEST_RESULT(command_get_status(command)==ERROR);
  command_destroy(command);
}

void test1_command_set_cmd()
{
  Command *command = NULL;
  command = command_create();
  PRINT_TEST_RESULT(command_set_cmd(command, MOVE)==OK);
  command_destroy(command);
}

void test2_command_set_cmd()
{
  Command *command = NULL;
  PRINT_TEST_RESULT(command_set_cmd(command, DROP)==ERROR);
}

void test1_command_get_cmd()
{
  Command *command = NULL;
  command = command_create();
  command_set_cmd(command, TAKE);
  PRINT_TEST_RESULT(command_get_cmd(command)==TAKE);
  command_destroy(command);
}

void test2_command_get_cmd()
{
  Command *command = NULL;
  PRINT_TEST_RESULT(command_get_cmd(command)==NO_CMD);
}

void test1_command_set_input()
{
  Command *command = NULL;
  command = command_create();
  PRINT_TEST_RESULT(command_set_input(command, "lukas")==OK);
  command_destroy(command);
}

void test2_command_set_input()
{
  Command *command = NULL;
  PRINT_TEST_RESULT(command_set_input(command, "pollo")==ERROR);
}

void test3_command_set_input()
{
  Command *command = NULL;
  command = command_create();
  PRINT_TEST_RESULT(command_set_input(command, NULL)==ERROR);
  command_destroy(command);
}

void test1_command_get_input()
{
  Command *command = NULL;
  command = command_create();
  command_set_input(command, "rata");
  PRINT_TEST_RESULT(strcmp(command_get_input(command), "rata")==0);
  command_destroy(command);
}

void test2_command_get_input()
{
  Command *command = NULL;
  PRINT_TEST_RESULT(command_get_input(command)==NULL);
}


