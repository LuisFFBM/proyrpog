/**
 * @brief It declares the tests for the inventory module
 *
 * @file inventory_test.h
 * @author oskar
 * @version 3.0
 * @date 24-03-2022
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H


/**
 * @test Test inventory creation
 * @pre new inventory info
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test inventory creation
 * @pre new inventory info with wrong nobjs
 * @post NULL pointer to inventory
 */
void test2_inventory_create();

/**
 * @test Test inventory destroy function
 * @pre new inventory info
 * @post OK
 */
void test1_inventory_destroy();

/**
 * @test Test inventory destroy function
 * @pre an inventory not initializated
 * @post ERROR
 */
 void test2_inventory_destroy();

/**
 * @test Test inventory is full
 * @pre inventory with not full
 * @post FALSE because inventory is not full
 */
void test1_inventory_is_full();

/**
 * @test Test inventory is full
 * @pre inventory without space for more objects
 * @post TRUE because inventory is full
 */

void test2_inventory_is_full();

/**
 * @test Test inventory add objects
 * @pre add an object in a inventory
 * @post OK everything is right
 */
void test1_inventory_add_object();

/**
 * @test Test inventory add object
 * @pre add not existing object in invenntory struct
 * @post ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test inventory remove object
 * @pre remove an existing object from the inventory
 * @post OK everything is right
 */
void test1_inventory_remove_object();

/**
 * @test Test inventory remove object
 * @pre remove an not existing object from the inventory
 * @post FALSE
 */
void test2_inventory_remove_object();

/**
 * @test Test inventory get objects
 * @pre comprove if the object's set is empty
 * @post TRUE
 */
void test1_inventory_get_objects();

/**
 * @test Test inventory get objects
 * @pre an non empty set of the inventory
 * @post non NULL pointer
 */
void test2_inventory_get_objects();

/**
 * @test Test enemy creation
 * @pre an empty set of the inventory
 * @post NULL pointer
 */
void test3_inventory_get_objects();

/**
 * @test Test inventory get nobjs
 * @pre new inventory info with a nobjs data
 * @post nobjs data
 */
void test1_inventory_get_n_objs();

/**
 * @test Test inventory get nobjs
 * @pre new inventory without nobjs data
 * @post error code
 */
void test2_inventory_get_n_objs();

/**
 * @test test inventory set max objs
 * @pre set wrong parameter in nobjs
 * @post ERROR
 */
void test1_inventory_set_max_objs();

/**
 * @test Test inventory set max objs
 * @pre new inventory info and change their max objects
 * @post 3
 */
void test2_inventory_set_max_objs();
#endif