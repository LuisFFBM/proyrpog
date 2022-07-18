/**
 * @brief It declares the tests for the space module
 *
 * @file space_test.h
 * @author Profesores PPROG, Javii
 * @version 3.0
 * @date 09-03-2022
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID
 * @post Non NULL pointer to space
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (pointer to space = NON NULL)
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_object setting
 * @pre pointer to space = NON NULL; object ID
 * @post Output==OK
 */
void test1_space_add_object();

/**
 * @test Test function for space_object setting
 * @pre pointer to space = NULL; space ID
 * @post Output==ERROR
 */
void test2_space_add_object();

/**
 * @test Test function for space_name getting
 * @pre pointer to space (initialized with a name)
 * @post Space_name == Supplied space name
 */
void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre pointer to space = NULL
 * @post Space_name == NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_objects getting
 * @pre pointer to space without objects
 * @post Set_is_empty == TRUE
 */
void test1_space_get_objects();

/**
 * @test Test function for space_objects getting
 * @pre pointer to space with an object
 * @post Space_get_objects = set with the obj. added previously != NULL
 */
void test2_space_get_objects();

/**
 * @test Test function for space_objects getting
 * @pre pointer to space = NULL
 * @post Space_get_objects == NULL
 */
void test3_space_get_objects();

/**
 * @test Test function for space_id getting
 * @pre pointer to space
 * @post Space_get_id = the space ID set previously != NO_ID
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre pointer to space = NULL
 * @post Space_get_id == NO_ID
 */
void test2_space_get_id();

#endif
