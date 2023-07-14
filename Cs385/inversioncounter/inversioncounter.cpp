/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Julia Nelson
 * Version     : 1.0
 * Date        : March 30, 2020
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

static long mergesort(int array[], int scratch[], int low, int high);

/**
 * (slow) Counts the number of inversions in an array in theta(n^2) time.
 * 
 */
long count_inversions_slow(int array[], int length) {
    long count = 0; 

    for(int i = 0; i < length - 1; i++ ) {              
        for(int j = i + 1; j < length; j++) {        
            if( array[i] > array[j]){               
                count++;
            }
        }
    }
    return count;

}

/**
 *  (fast) Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    // TODO
    // Hint: Use mergesort!
    long counter = 0;
    int *scratch = new int[ length ];
    counter = mergesort(array, scratch, 0, length - 1 );
    delete[] scratch;
    return counter;
}


/* 
* Really unsure how to do this without this function..
*/
static long merger(int array[], int scratch[], int low, int mid, int high) {
    int i = low;
    int j = mid;
    int k = low;
    long inversionCount = 0;
    while ( ( i <= mid - 1 ) && ( j <= high ) ) {
        if (array[i] <= array[j]){ 
            scratch[k++] = array[i++];
        } 
        else {
            scratch[k++] = array[j++];
            inversionCount += (mid - i); 
        }
    }
    while (i <= mid - 1){ 
        scratch[k++] = array[i++];
    }
    while (j <= high){ 
        scratch[k++] = array[j++];
    }
    for (i=low; i <= high; i++){
        array[i] = scratch[i]; 
    }
    return inversionCount;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    // TODO
    long mid;
    long counter = 0;
    if (low < high) {
        mid = (low + high) / 2; 
        counter = mergesort(array, scratch, low, mid); 
        counter += mergesort(array, scratch, mid + 1, high); 
        counter += merger(array, scratch, low, mid + 1, high); 
    }
    return counter;
}



int main(int argc, char *argv[]) {
    // TODO: parse command-line argument
    bool useFast;
    if (argc > 2) {                
        cerr << "Usage: ./inversioncounter [slow]" << endl;
        return 1;
    }

    if(argv[1] != NULL ){           
        if(strcmp(argv[1], "slow") != 0){       
            cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
            return 1;
        }
        useFast = false;        
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

    // TODO: produce output
    if(values.empty()){
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }
    if(values.size() == 1){
        cout << "Number of inversions: 0"  << endl;
        return 1;
    }
    else{
        if( useFast == true){
            // if slow command line specification, call slow counter
            cout << "Number of inversions: " << count_inversions_fast(&values[0], values.size()) << endl;
            return 0;
        }
        if( useFast == false){
            cout << "Number of inversions: " << count_inversions_slow(&values[0], values.size()) << endl;   
            return 0;
        }
    }
    return 0;
}
