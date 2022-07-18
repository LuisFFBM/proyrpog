#ifndef GAME_READER_TEST
#define GAME_READER_TEST

/**
 * @test Test space reading
 * @pre file is created and values read
 * @post Correct values when retrieved by setters
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
 * @post Correct values when retrieved by setters
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
 * @post Correct values when retrieved by setters
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
 * @post Correct values when retrieved by setters
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
#endif
