/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Juila Nelson
 * Version     : 1.0
 * Date        : October 25, 2019
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
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
    int counter = 0;
    for(int i = 0; i <= length-1; ++i){                    // SUPPOSED TO BE .... i<n-1; i++)
        for(int j = 1; j<length; j++){                       // SUPPOSED TO BE .... j=i+1; j++)
            if( array[j] < array[i]){
                counter += 1;
            }
        }
    }
    return counter;                                 // MAYBE SUPPOSED TO BE .... inside loop?                 
}





/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    // TODO
    // Hint: Use mergesort!
}





static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO
}





int main(int argc, char *argv[]) {


    // TODO: parse command-line argument

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

    return 0;
}
