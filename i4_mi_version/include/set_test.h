/**
 * @brief It declares the tests for the set module
 *
 * @file set_test.h
 * @author Álexx, Javii
 * @version 3.0
 * @date 14-03-2022
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @pre
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set_add, that adds an element to the set
 * @pre element ID twice, pointer to set
 * @post Output==ERROR
 */
void test1_set_add();

/**
 * @test Test set_add, that adds an element to the set
 * @pre pointer to set = NULL
 * @post Output==ERROR
 */
void test2_set_add();

/**
 * @test Test set_add and set_del
 * @pre ID of an element to add and del., pointer to set
 * @post Output==OK
 */
void test1_set_del();

/**
 * @test Test set_del
 * @pre pointer to set = NULL
 * @post Output==ERROR
 */
void test2_set_del();

/**
 * @test Test set_del
 * @pre ID of an element to del., different to the one added;
 *      pointer to set
 * @post Output==ERROR
 */
void test3_set_del();

/**
 * @test Test set_n_ids getting
 * @pre pointer to set with n elements
 * @post n
 */
void test1_set_get_n_ids();

/**
 * @test Test set_ids getting
 * @pre pointer to set with n elements
 * @post array with the ids
 */
void test1_set_get_ids();

/**
 * @test Test set_id_in_set, that finds out if an specific ID
 *       is in the set
 * @pre IDs of elements in the set
 * @post TRUE
 */
void test1_set_id_in_set();

/**
 * @test Test set_is_empty
 * @pre pointer to an empty set
 * @post TRUE
 */
void test1_set_is_empty();

/**
 * @test Test set_is_empty
 * @pre pointer to a non empty set
 * @post FALSE
 */
void test2_set_is_empty();

#endif
