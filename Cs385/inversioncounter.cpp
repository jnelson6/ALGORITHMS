/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      :
 * Version     : 1.0
 * Date        :
 * Description : Counts the number of inversions in an array.
 * Pledge      :
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    // TODO
    return 0;////////////////
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    // TODO
    // Hint: Use mergesort!
    return 0;////////////////
}

static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO
    return 0;////////////////
}

int main(int argc, char *argv[]) {
    // TODO: parse command-line argument
    bool useFast;
                // automatically use Fast version unless otherwise specified

    if (argc > 2) {                 // when there is more than 2 command line arguments ( other than name of file and "slow")
        cerr << "Usage: ./inversioncounter [slow]" << endl;
        return 1;
    }

    if(argv[1] != NULL ){           // if there is a command line argument input
        if(strcmp(argv[1], "slow") != 0){       // if the argument is something other than "slow" specification
            cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
            return 1;
        }
         useFast = false;        // if command line state "slow" set useFast to false to call count_inversions_slow()
    }
    if(argv[1] == NULL ){
         useFast = true;
    }
/////////////

    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    // TODO: produce output

// if no input
    if(values.empty()){
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;            
    }
    // if only 1 input in array return 0
    if(values.size() == 1){
        cout << "Number of inversions: 0"  << endl;
        return 1;            
    }
    else{
        // if no command line specification, call fast counter
        if( useFast == false){
            cout << "Number of inversions: " << count_inversions_slow(&values[0], values.size()) << endl;   // size represents length of the vector
                return 0;
        }
        if( useFast == true){
            // if slow command line specification, call slow counter
            cout << "Number of inversions: " << count_inversions_fast(&values[0], values.size()) << endl;
                return 0;
            }
        }


///////////





    return 0;
}











