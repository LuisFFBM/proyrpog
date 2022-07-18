/**
 * @brief it defines the game_management tests interface
 * @file game_management_test.h
 * @author oskar
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright GNU p
 * 
 */

#ifndef game_management_TEST
#define game_management_TEST

/**
 * @test Test space reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_load_spaces();


/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_load_spaces
 * @post ERROR
 */
void test2_load_spaces();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_load_spaces
 * @post ERROR
 */
void test3_load_spaces();

/**
 * @test Test object reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_load_object();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_load_objects
 * @post ERROR
 */
void test2_load_object();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_load_objects
 * @post ERROR
 */
void test3_load_object();

/**
 * @test Test player reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_load_player();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_load_player
 * @post ERROR
 */
void test2_load_player();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_load_player
 * @post ERROR
 */
void test3_load_player();

/**
 * @test Test links reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_load_link();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_load_links
 * @post ERROR
 */
void test2_load_link();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_load_links
 * @post ERROR
 */
void test3_load_link();

/**
 * @test Test dialogues reading
 * @pre file is created and values are read
 * @post Correct values when retrieved by getters
 */
void test1_load_dialogue();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_management_load_dialogues
 * @post ERROR
 */
void test2_load_dialogue();

/**
 * @test Test passing NULL to game parameter
 * @pre NULL game pointer is passed to game_reder_load_dialogues
 * @post ERROR
 */
void test3_load_dialogue();

/**
 * @test Test space reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_save_spaces();


/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_save_spaces
 * @post ERROR
 */
void test2_save_spaces();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_save_spaces
 * @post ERROR
 */
void test3_save_spaces();

/**
 * @test Test object reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_save_object();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_save_objects
 * @post ERROR
 */
void test2_save_object();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_save_objects
 * @post ERROR
 */
void test3_save_object();

/**
 * @test Test player reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_save_player();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_save_player
 * @post ERROR
 */
void test2_save_player();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_save_player
 * @post ERROR
 */
void test3_save_player();

/**
 * @test Test links reading
 * @pre file is created and values read
 * @post Correct values when retrived by getters
 */
void test1_save_link();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_reder_save_links
 * @post ERROR
 */
void test2_save_link();

/**
 * @test Test passing NULL to game parameter
 * @pre non exiting file is passed to game_reder_save_links
 * @post ERROR
 */
void test3_save_link();

/**
 * @test Test dialogues reading
 * @pre file is created and values are read
 * @post Correct values when retrieved by getters
 */
void test1_save_dialogue();

/**
 * @test Test passing unexising file
 * @pre non exiting file is passed to game_management_save_dialogues
 * @post ERROR
 */
void test2_save_dialogue();

/**
 * @test Test passing NULL to game parameter
 * @pre NULL game pointer is passed to game_reder_save_dialogues
 * @post ERROR
 */
void test3_save_dialogue();


#endif
