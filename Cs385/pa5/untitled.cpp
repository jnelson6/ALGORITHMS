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
 * Slow - nested loops
 */
long count_inversions_slow(int array[], int length) {
    long counter = 0;                               // Used "long" not "int" because int was failing test cases with lots of arguments 
    for(int i = 0; i < length-1; i++){              // length-1 because i represents the front index of the compare statement
        for(int j = i + 1; j < length; j++){        // j+1 and not length-1 to get index after i including final index of array                                          
            if( array[i] > array[j]){               // if the value of index i is before index j and bigger, add 1 to counter
                counter++;
            }
        }
    }
    return counter;                                              
}


/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 * Fast - modified mergesort
 */
long count_inversions_fast(int array[], int length) {
    // NOT SURE IF CORRECT PLEASE HELP
    // Call mergesort!
    long counter = 0;
    int *scratch = new int[length];
    
    counter = mergesort(array, scratch, 0, length-1);

    delete[] scratch;
    
    return counter;
    /*
    int *scratch = new int[length];
    long counter = mergesort(array, scratch, 0, length-1);
    delete[] scratch;
    return counter;
    */
}

static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO - YOU GOT THIS
    //create an empty array to hold the sorted list
    int mid = low + (high - low);   // that's correct great job  need a new formula to what if uneven # for high?
 
    //scratch = array;
    long total_inversions = 0;
     
    //next we create crawlers for both intervals and the sorted array
    int i = low;
    int j = mid;
    int k = 0;


    //next we taverse both arrays and in each iteration add the smaller element 
    // of both elements into our sorted  
    while( i <= mid && j <= high){  //&& j <= high
        if (array[i] <= array[j]){
            //count_inversions_fast(array, sizeof(array)/ sizeof(array[0]));
            //total_inversions++;
            scratch[k++] = array[j++];
            
        }else{
            scratch[k++] = array[j++];
            
            total_inversions = total_inversions + (mid - i);
        }
    } 
    while(i <= (mid-1)){
        scratch[k++] = array[i++];
    }
    //add elements that are left in the second interval
    while(j <= high){
        scratch[k++] = array[j++];
    }
    //merge the arrays by copying our newly sorted array to the orignal
    for( i = 0; i <= high - low ; i++){
        array[i+low] = scratch[i];
    }
    return total_inversions;
}





int main(int argc, char *argv[]) {

    bool useFast;
    // parse command-line argument
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
