/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Julia Nelson
 * Date        : September 20, 2019
 * Description : Determining uniqueness of chars with int as bit vector. 
 				You may NOT use the C++ bitset or any other library in your project.  
				You MUST use a single unsigned int to represent your bitset 
     			and use bitshifting and bitwise operations.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;


	// TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
bool is_all_lowercase(const string &s) {
	for(char c : s){
		if (!(c >= 'a' and c <= 'z')) return false;
	}
	return true;
}


    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
bool all_unique_letters(const string &s) {
    if(!is_all_lowercase(s)) return false;

    // seen is a 32-bit bitset. seen no letters yet.
    int letters_seen_bit_mask = 0;
    // for every character in the string
    for (const auto & letter: s) {
        // Create bit mask from lower 5 bits of ASCII code.
        // That fits within 32-bit bitset for [a..zA..Z] and
        // will produce same value for 'a' and 'A'.
        int letter_bit_mask = 1 << (letter & 0x1F);

        // If the letter was seen already, return false
        if (letters_seen_bit_mask & letter_bit_mask) return false;

        // if haven't seen letter, add it to seen
        letters_seen_bit_mask |= letter_bit_mask;
    }
    // if false not returned inside the loop, it must be unique
    return true;
}


    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
int main(int argc, char * const argv[]) {

    if(argc != 2){
    	cout << "Usage: ./unique <string>" << endl;
    	return 0;
    }

    else{
    	string s = string(argv[1]);

    	if(!is_all_lowercase(s)){
    		cout << "Error: String must contain only lowercase letters." << endl;
    	}
    	else{
    		if(all_unique_letters(s)){
    			cout << "All letters are unique." << endl;
    		}
    		else{
    			cout << "Duplicate letters found." << endl;
    		}
    	}
    	return 1;
    }
}
