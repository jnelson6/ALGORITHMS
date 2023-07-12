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
 * (slow)
 */
long count_inversions_slow(int array[], int length) {
    // TODO
    long counter = 0;                               // Used "long" not "int" because int was failing test cases with lots of arguments
    for(int i = 0; i < length-1; i++){              // length-1 because i represents the front index of the compare statement
        for(int j = i + 1; j < length; j++){        // j+1 and not length-1 to get index after i including final index of array
            if( array[i] > array[j]){               // if the value of index i is before index j and bigger, add 1 to counter
                counter++;
            }
        }
    }
    return counter;
    ///
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    // TODO
    // Hint: Use mergesort!
    long counter = 0;
    int *scratch = new int[length];
    counter = mergesort(array, scratch, 0, length-1);
    delete[] scratch;
    return counter;
}


/* I ADDED THIS FUNCTION BUT ITS NOT WORKING SO MUST NOT BE RIGHT
*/
static long merger(int array[], int scratch[], int low, int mid, int high) {
    int i = low;
    int j = mid;
    int k = low;
    long inversionCount = 0;

    while ( ( i <= mid - 1 ) && ( j <= high ) ) {
        if (array[i] <= array[j]){ //when low item is less than high item
            scratch[k++] = array[i++];
        } else {
            scratch[k++] = array[j++];
            inversionCount += (mid - i); //find how many convertion is performed
        }
    }
    while (i <= mid - 1){ //if first list has remaining item, add them in the list
        scratch[k++] = array[i++];
    }
    while (j <= high){ //if second list has remaining item, add them in the list
        scratch[k++] = array[j++];
    }
    for (i=low; i <= high; i++){
        array[i] = scratch[i]; //store (temp) scratch array to main array
    }
    return inversionCount;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO
    long mid;
    long count = 0;
    if (high > low) {
        mid = (high + low)/2; //find mid index of the array... wont allow other way to find min
        count = mergesort(array, scratch, low, mid); //merge sort left sub array
        count += mergesort(array, scratch, mid+1, high); //merge sort right sub array
        count += merger(array, scratch, low, mid+1, high); //merge two sub arrays
    }
    return count;
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
