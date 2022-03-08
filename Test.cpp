/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(49, 7, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@-----------------------------------------------@\n"
"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
"@-@-------------------------------------------@-@\n"
"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
"@-----------------------------------------------@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));


	CHECK(nospaces(mat(21, 7, '@', '-')) == nospaces(
"@@@@@@@@@@@@@@@@@@@@@\n"
"@-------------------@\n"
"@-@@@@@@@@@@@@@@@@@-@\n"
"@-@---------------@-@\n"
"@-@@@@@@@@@@@@@@@@@-@\n"
"@-------------------@\n"
"@@@@@@@@@@@@@@@@@@@@@"));

CHECK(nospaces(mat(47, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"@---------------------------------------------@\n"
"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
"@-@-----------------------------------------@-@\n"
"@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@\n"
"@-@-----------------------------------------@-@\n"
"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
"@---------------------------------------------@\n"
"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));				 												 
  
													 
	/* Add more test here */
}

TEST_CASE("Bad input") {
	//Mat size is always odd
	CHECK_THROWS(mat(49, 300, '$', '%'));
	CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(2, 5, '$', '%'));
	CHECK_THROWS(mat(4, 200, '$', '%'));
	CHECK_THROWS(mat(100, 7, '$', '%'));

    //The col is too much
	CHECK_THROWS(mat(51,7, '@', '-'));
	CHECK_THROWS(mat(101,11, '@', '-'));
	CHECK_THROWS(mat(301,11, '@', '-'));
	CHECK_THROWS(mat(401,11, '@', '-'));
	CHECK_THROWS(mat(501,11, '@', '-'));


	//Mat size is always positive
	CHECK_THROWS(mat(-11,11, '@', '-'));
	CHECK_THROWS(mat(-11,-11, '@', '-'));
	CHECK_THROWS(mat(11,-11, '@', '-'));
	CHECK_THROWS(mat(0,0, '@', '-'));
	CHECK_THROWS(mat(0,11, '@', '-'));
	CHECK_THROWS(mat(11,0, '@', '-'));


	//The signs must be different
	CHECK_THROWS(mat(11,11, '@', '@'));
	CHECK_THROWS(mat(11,11, '&', '&'));
	CHECK_THROWS(mat(11,11, '-', '-'));
	CHECK_THROWS(mat(11,11, '!', '!'));
	CHECK_THROWS(mat(11,11, '*', '*'));
	CHECK_THROWS(mat(11,11, '%', '%'));
	CHECK_THROWS(mat(11,11, '^', '^'));
	CHECK_THROWS(mat(11,11, '$', '$'));
	CHECK_THROWS(mat(11,11, '#', '#'));

	//Invalid icon
	CHECK_THROWS(mat(11,11, 8, '#'));
	CHECK_THROWS(mat(11,11, '#', 8));
	


    /* Add more test here */
}


