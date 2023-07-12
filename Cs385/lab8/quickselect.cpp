/******************************************************************************* 
* Name          : quickselect.cpp 
* Author        : Julia Nelson
* Pledge        : I pledge my honor that I have abided by the Stevens Honor System.
* Date          : October 18, 2019
* Description   : Implements the quickselect algorithm found on page 160 in 
*                 Algorithms, 3e by Anany Levitin. 
******************************************************************************/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

size_t lomuto_partition(int array[], size_t left, size_t right) {
    // the lomuto partition takes and array with the  left and index right as arguments
    // using given left index as a pivot, function partitions each subarray 
    // returns the new position of the index for the pivot left (sorts the array)
    
    int p = array[left];    //sets the pivot p to be the left index of the inputed array
    size_t s = left;        // set initial output to be the left index 

    // increments the index counter var to help track which index were on for lomuto partition
    for(size_t index = left +1; index <= right; index++){   
        
        // if the value of element in the current index is < the pivot value (in left index of input array)
        if ( array[index] < p){
            s++;                            // shift the new position s up one index
            swap(array[s], array[index]);   // then swap the values in the new position s and the current index 
                                            // we are working on of the array 

        }
    }

    swap(array[left], array[s]);    // finally swap the values in index left and s 
    return s;                       // then return the position of s that has the new value
}

int quick_select(int array[], size_t left, size_t right, size_t k) {
    // a helper function for full quick_select that calls lomuto partition function
    // INPUT: takes in extra length argument of the array size_t left and size_t right instead of full length
    // OUTPUT: when the index = sorted kth int in the array

    // sets var of s to represent the return of new position of partitioned subarray from call to lomuto 
    size_t s = lomuto_partition(array, left, right);

    // if the lomuto partition index s is = to the sorted kth - 1 int of the array 
    // return the value of the new position s in array
    if (s == k-1){
        return array[s];
    }
    // if the right and left equal then return left index of array
    if (right - left == 0){
        return array[left];
    }
    // when the new position s is less than k-1 index, set position of left to s+1 to continue sorting 
    else if( s < k-1){
        return quick_select(array, s+1, right, k);

    }
    else{   // else when s > k-1.. set right to s-1 (1 below new position of s is now new right index) 
        return quick_select(array, left, s - 1, k);
    }
}



int quick_select(int array[], const size_t length, size_t k) {
    return quick_select(array, 0, length - 1, k);
}



int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <k>" << endl;
        return 1;
    }

    int k;
    istringstream iss;
    iss.str(argv[1]);
    if ( !(iss >> k) || k <= 0 ) {
        cerr << "Error: Invalid value '" << argv[1] << "' for k." << endl;
        return 1;
    }

    cout << "Enter sequence of integers, each followed by a space: " << flush;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    iss.clear();
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

    int num_values = values.size();
    if (num_values == 0) {
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }
    // TODO - error checking k against the size of the input

    // when size k of array is larger than the size of vector of int values errors can arrise
    if(k > num_values){

        // if array values is = 1 (and k is greater than that, then you cannot find smallest 
        //                                      kth element when there is only 1 value )
        if (num_values == 1){
            cerr << "Error: Cannot find smallest element " << k << " with only " << values.size() << " value." << endl;

        }

        
        // if array values is > 1 (but k is greater than that value, then you cannot find smallest 
        //                                      kth element with less values than that )
        if(num_values > 1){
            cerr << "Error: Cannot find smallest element " << k << " with only " << values.size() << " values." << endl;

        }

        return 1;   // error

    }

    // TODO - call the quick_select function and display the result

    // while printing, calls the true quick_select on array of inputed values[0], with length of num_values 
    //                                                                          and key k for element to sort for
    cout << "Smallest element " << k << ": " << quick_select(&values[0], num_values, k) << endl;

    return 0;   // success
}















