/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Julia Nelson
 * Date        : 02/18/2020
 * Description : Determining uniqueness of chars with int as bit vector. 
 				  (determines if a string has all unique lowercase letters)
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;


/**
* Input takes in the reference to a string
* Returns true if all characters in the string are lowercase
* 			letters (in the English Alphabet)
* Returns false otherwise
*/
bool is_all_lowercase(const string &s) {

	for( char n : s) {
		if( n <= 'z' && n >= 'a'){
				return true;
		}
	}
	return false;
}



/**
* Input takes in const reference to a string
* Returns true f all letters in string are unique
* 		  ( no duplicates )
* Returns false otherwise
*/
bool all_unique_letters(const string &s) {

	if( is_all_lowercase(s) != true ){ 
		return false;
	}
	else{
		int seen_letters = 0;
    	for (const auto &  chars : s) {				// for every character in the string - shown in class by Dr. B 
        	int mask = 1 << (chars & 0x1F);			// compares to alphabet
        	if (seen_letters & mask) {				// when char seen already -> return false
        		return false;
        	}
        	seen_letters |= mask;		 			// unseen letter -> add to seen_letters (|= operator found on stack overflow)
    	}
	}
    return true;
}




/**
 * Main functions reads and pases command line args and calls
 * other functions to produce correct output.
 */
int main(int argc, char * const argv[]) {



    if(argc != 2){

    	cout << "Usage: ./unique <string>" << endl;
    	return 0;
    }

    string s = string(argv[1]);
    if(is_all_lowercase(s) == false){
    	cout << "Error: String must contain only lowercase letters." << endl;
		return 0;
    }

    if(is_all_lowercase(s) == true){
    		// checks for integers 
    		for( char n : s){
   				if( n == '0' || n == '1' || n == '2' || n == '3' || n == '4' || n == '5' || n == '6' || n == '7' || n == '8' || n == '9' ){
   					cout << "Error: String must contain only lowercase letters." << endl;
					return 0;
   				}
   			}

			if(all_unique_letters(s)){
    			cout << "All letters are unique." << endl;
    			return 0;
    		}
    		else{
    			cout << "Duplicate letters found." << endl;
    			return 0;
    		}



    	}
    	return 1;
    }

   





























