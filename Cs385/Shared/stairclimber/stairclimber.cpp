/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Julia Nelson
 * Date        : February 28, 2020
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;


/**
* Takes in int num_stairs wanting to climb
* Returns vector of vectors of ints representing the different 
* combinations of ways to climb num_stairs stairs, moving up 
* either 1, 2, or 3 stairs at a time
*/
vector< vector<int> > get_ways(int num_stairs) {
	vector< vector<int> > nums;
	vector< vector<int> > ways;
    if ( num_stairs <= 0 ){					// if number of stairs needed to climb = 0
        vector<int> empty;					// new empty vector
        ways.push_back(empty);				// empty vector pushed onto vector ways
    }
    else {
        for ( int i = 1; i < 4; i++ ) {									// i < 4 stairs, only allowed input num stairs 1-3 
            if ( num_stairs >= i ) {
                nums = get_ways( num_stairs - i );						// sets vector nums to recursive call to get_ways 
                for ( auto it = nums.begin(); it != nums.end(); it++ ) {// iterator 
                    (*it).insert( (*it).begin(), i );					// inserts num step  
                    ways.push_back(*it);								// push nums vector onto ways vector
                }
            }
        }
    }
    return ways;   
}


/**
* Takes in input vector of vectors of ints 
* displays the ways of climbing the stairs by iterating through
* the vector of vectors and prints every combination
*/
void display_ways(const vector< vector<int> > &ways) {
 	int digs = 0;			
    for ( int n = ways.size(); n != 0; digs++ ){					// max digits for display
        n /= 10;
    }
    for ( unsigned int i = 0; i < ways.size(); i++ ){						// finds size (or number of) ways found to print **** UNSIGNED
        cout << setw(digs) << ( 1 + i ) << ". [" ;							// properly numbers the ways to climb 

        for ( auto it = ways[i].begin(); it != ways[i].end(); it++ ){
            cout << *it;													// print the step num value from vector ways that iterator is on 
            if ( it != (ways[i].end() - 1 )){								// if not at end of vector, print ','
                cout << ", ";
            }
        }

        if ( i != ways.size() - 1 ){						// if all nums vector of ways vector have been printed
            cout << "]" << endl;							// endl; -> to stop printing
        }
        else{												// else, allow for more vectors to be printed
            cout << "]";
        }
    }
}

/**
* Helper function to display and call other functions
*/ 
void display_helper(const int num_stairs){
	vector< vector<int> > ways;
	ways = get_ways(num_stairs);
	if (ways.size() == 1){											// proper grammer for specific case of 1 stair
        cout << "1 way to climb ";
    }
    else{
        cout << ways.size() << " ways to climb ";
    }
    if (num_stairs == 1){											// proper grammer for specific case of 1 stair
        cout << "1 stair." << endl;
    }
    else{
        cout << num_stairs << " stairs." << endl;
    }
    display_ways(ways);
}




int main(int argc, char * const argv[]) {
    if (argc != 2) {
        cout << "Usage: ./stairclimber <number of stairs>";
        return 1;
    }
    int num_stairs = atoi(argv[1]);										// sets input for number of stairs to climb
    if (num_stairs <= 0){					
        cout << "Error: Number of stairs must be a positive integer.";
        return 1;
    }
    display_helper(num_stairs);
    return 0;
}










