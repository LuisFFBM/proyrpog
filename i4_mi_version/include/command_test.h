/** 
 * @brief It declares the tests for the command module
 * 
 * @file command_test.h
 * @author Joaquin Abad, Alexx
 * @version 0.1
 * @date 24-03-2022
 */

#ifndef COMMAND_TEST_H
#define COMMAND_TEST_H


/**
 * @test Test command creation
 * @pre Nothing
 * @post Non NULL pointer to command
 */
void test1_command_create();

/**
 * @test Test command set status
 * @pre Non NULL pointer to command and a STATUS to set
 * @post command_set_status == OK
 */
void test1_command_set_status();

/**
 * @test Test command set status
 * @pre NULL pointer to command and a STATUS to set
 * @post command_set_status == ERROR
 */
void test2_command_set_status();

/**
 * @test Test command get status
 * @pre Non NULL pointer to command with a STATUS setted
 * @post STATUS getted correctly
 */
void test1_command_get_status();

/**
 * @test Test command get status
 * @pre Non NULL pointer to command with a STATUS setted
 * @post STATUS getted correctly
 */
void test2_command_get_status();

/**
 * @test Test command set cmd
 * @pre Non NULL pointer to command and a cmd to set
 * @post command_set_cmd == OK
 */
void test1_command_set_cmd();

/**
 * @test Test command set cmd
 * @pre NULL pointer to command and a cmd to set
 * @post command_set_cmd == ERROR
 */
void test2_command_set_cmd();

/**
 * @test Test command get cmd
 * @pre Pointer to command with a cmd setted
 * @post Cmd getted correctly
 */
void test1_command_get_cmd();

/**
 * @test Test command get cmd
 * @pre NULL pointer to command
 * @post command_get_cmd == NO_CMD
 */
void test2_command_get_cmd();

/**
 * @test Test command get input
 * @pre Non NULL pointer to command with an input to set
 * @post command_set_input == OK
 */
void test1_command_set_input();

/**
 * @test Test command get input
 * @pre NULL pointer to command with an input to set
 * @post command_set_input == ERROR
 */
void test2_command_set_input();

/**
 * @test Test command get input
 * @pre NULL pointer to command with an input (NULL) to set
 * @post command_set_input == ERROR
 */
void test3_command_set_input();

/**
 * @test Test command get input
 * @pre Non NULL pointer to command with input setted
 * @post Input getted correctly
 */
void test1_command_get_input();

/**
 * @test Test command get input
 * @pre NULL pointer to command
 * @post command_get_input == NULL
 */
void test2_command_get_input();


#endif
