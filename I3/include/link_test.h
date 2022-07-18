/**
 * @brief It declares the tests for the link module
 *
 * @file link_test.h
 * @author Luis
 * @version 3.0
 * @date 04-04-2022
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre Link ID
 * @post Non NULL pointer to link
 */
void test1_link_create();

/**
 * @test Test Link creation
 * @pre Link ID
 * @post Link_ID == Supplied Link Id
 */
void test2_link_create();

/**
 * @test Test Link destruction
 * @pre Link initialized
 * @post Link_ID == Supplied Link Id
 */
void test2_link_create();

/**
 * @test Test Link destruction
 * @pre Link initialized
 * @post Link_ID == Supplied Link Id
 */
void test3_link_create();

/**
 * @test Test Link destruction
 * @pre Link initialized
 * @post Link_ID == Supplied Link Id
 */
void test1_link_destroy();

/**
 * @test Test Link destruction
 * @pre Link initialized
 * @post Link_ID == Supplied Link Id
 */
void test2_link_destroy();

/**
 * @test Test link_get_id
 * @pre Link initialized with id != NO_ID
 * @post link_get_id == Supplied Link Id 
 */
void test1_link_get_id();

/**
 * @test Test link_get_id
 * @pre Link uninitialized
 * @post link_get_id == NO_ID
 */
void test2_link_get_id();

/**
 * @test Test link_set_name
 * @pre Link initialized and name
 * @post link_set_name == OK && link.name == Supplied Link name
 */
void test1_link_set_name();

/**
 * @test Test link_set_name
 * @pre Link initialized and name
 * @post link_set_name == ERROR
 */
void test2_link_set_name();

/**
 * @test Test link_set_name
 * @pre Link uninitialized and name
 * @post link_set_name == ERROR
 */
void test3_link_set_name();

/**
 * @test Test link_get_name
 * @pre Link initialized with name supplied
 * @post link_get_name == supplied Link name
 */
void test1_link_get_name();

/**
 * @test Test link_get_name
 * @pre Link initialized without a name supplied
 * @post link_get_name == NULL
 */
void test2_link_get_name();

/**
 * @test Test link_get_name
 * @pre Link uninitialized 
 * @post link_get_name == NULL
 */
void test3_link_get_name();

/**
 * @test Test link_set_status
 * @pre Link initialized and status(ERROR)
 * @post link_set_status == OK && link.status == ERROR
 */
void test1_link_set_status();

/**
 * @test Test link_set_status
 * @pre Link initialized and status <0
 * @post link_set_status == ERROR
 */
void test2_link_set_status();

/**
 * @test Test link_set_status
 * @pre Link initialized and status !=OK && !=ERROR && >0
 * @post link_set_status == ERROR
 */
void test3_link_set_status();

/**
 * @test Test link_set_status
 * @pre Link uninitialized and status(ERROR)
 * @post link_set_status == ERROR
 */
void test4_link_set_status();

/**
 * @test Test link_get_status
 * @pre Link initialized and status(ERROR)
 * @post link_get_status == ERROR
 */
void test1_link_get_status();

/**
 * @test Test link_get_status
 * @pre Link initialized
 * @post link_get_status == OK
 */
void test2_link_get_status();

/**
 * @test Test link_get_status
 * @pre Link uninitialized
 * @post link_get_status == ERROR
 */
void test3_link_get_status();

/**
 * @test Test link_set_origin
 * @pre Link initialized and origin Id (2)
 * @post link_set_origin == OK && link.origin == 2
 */
void test1_link_set_origin();

/**
 * @test Test link_set_origin
 * @pre Link initialized and origin NO_ID
 * @post link_set_origin == ERROR
 */
void test2_link_set_origin();

/**
 * @test Test link_set_origin
 * @pre Link uninitialized and origin Id 2
 * @post link_set_origin == ERROR
 */
void test3_link_set_origin();

/**
 * @test Test link_get_origin
 * @pre Link initialized and origin Id 2 
 * @post link_get_origin == 2
 */
void test1_link_get_origin();

/**
 * @test Test link_get_origin
 * @pre Link initialized  
 * @post link_get_origin == NO_ID
 */
void test2_link_get_origin();

/**
 * @test Test link_get_origin
 * @pre Link uninitialized  
 * @post link_get_origin == NO_ID
 */
void test3_link_get_origin();

/**
 * @test Test link_set_destination
 * @pre Link initialized and destination Id (2)
 * @post link_set_destination == OK && link.destination == 2
 */
void test1_link_set_destination();

/**
 * @test Test link_set_destination
 * @pre Link initialized and destination NO_ID
 * @post link_set_destination == ERROR
 */
void test2_link_set_destination();

/**
 * @test Test link_set_destination
 * @pre Link uninitialized and destination Id 2
 * @post link_set_destination == ERROR
 */
void test3_link_set_destination();

/**
 * @test Test link_get_destination
 * @pre Link initialized and destination Id 2 
 * @post link_get_destination == 2
 */
void test1_link_get_destination();

/**
 * @test Test link_get_destination
 * @pre Link initialized  
 * @post link_get_destination == NO_ID
 */
void test2_link_get_destination();

/**
 * @test Test link_get_destination
 * @pre Link uninitialized  
 * @post link_get_destination == NO_ID
 */
void test3_link_get_destination();


/**
 * @test Test link_set_direction
 * @pre Link initialized and direction N
 * @post link_set_direction == OK && link.direction == N
 */
void test1_link_set_direction();


/**
 * @test Test link_set_direction
 * @pre Link initialized and direction NO_DIR
 * @post link_set_direction == ERROR
 */
void test2_link_set_direction();

/**
 * @test Test link_set_direction
 * @pre Link uninitialized and direction N
 * @post link_set_direction == ERROR
 */
void test3_link_set_direction();

/**
 * @test Test link_get_direction
 * @pre Link initialized and direction S
 * @post link_get_direction == S
 */
void test1_link_get_direction();

/**
 * @test Test link_get_direction
 * @pre Link initialized
 * @post link_get_direction == NO_DIR
 */
void test2_link_get_direction();

/**
 * @test Test link_get_direction
 * @pre Link uninitialized
 * @post link_get_direction == NO_DIR
 */
void test3_link_get_direction();


#endif