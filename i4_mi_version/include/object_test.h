/**
 * @file object_test.h
 * @author oskar
 * @brief It declares the tests for the sobject module
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef OBJECT_TEST
#define OBJECT_TEST


/**
 * @test Test object creation
 * @pre new object info
 * @post NON NULL pointer to object
 */
void test1_object_create();

/**
 * @test Test object creation
 * @pre new object info
 * @post NON NULL pointer to object and all object info provided
 */
void test2_object_create();

/**
 * @test Test function for object_name setting and getting
 * @pre pointer to object initialized and new object name
 * @post object_get_name = last name set
 */
void test1_object_set_name();

/**
 * @test Test function for object_name setting
 * @pre pointer to object = NULL; object name
 * @post Output==ERROR
 */
void test2_object_set_name();

/**
 * @test Test function for object_id setting
 * @pre pointer to object = NULL; object  id
 * @post Output == ERROR
 */
void test1_object_set_id();

/**
 * @test Test function for object_id setting and getting
 * @pre pointer to object initialized and new object id
 * @post obect_get_id = last id set
 */
void test2_object_set_id();

/**
 * @test Test function for object name gatting
 * @pre Pointer to object = NULL
 * @post object_name = NULL
 */
void test1_object_get_name();

/**
 * @test Test function for object_name getting
 * @pre pointer to object initialized 
 * @post obect_name = Supplied object name
 */
void test2_object_get_name();

/**
 * @test Test function for object_id getting
 * @pre pointer to object
 * @post Space_get_id = the object ID set previously != NO_ID
 */
void test1_object_get_id();

/**
 * @test Test function for object_id getting
 * @pre pointer to object = NULL
 * @post Space_get_id == NO_ID
 */
void test2_object_get_id();

/**
 * @test Test function for object_description setting
 * @pre pointer to object initialized and new description
 * @post same string
 */
void test1_object_set_description();
/**
 * @test Test function for object_description setting
 * @pre pointer to object == NULL
 * @post obect_set_descr == ERROR
 */
void test2_object_set_description();

/**
 * @test Test function for object descr getting
 * @pre pointer to object == NULL 
 * @post obect_get_description = ERROR
 */
void test1_object_get_description();

/**
 * @test Test function for object_id getting
 * @pre pointer to object initialized and new object idescription
 * @post obect_get_description = last descr
 */
void test2_object_get_description();


#endif

  