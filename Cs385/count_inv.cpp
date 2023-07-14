#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
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
static long count_inversions_fast(vector<int> arr, int scratch[], int low, int high)
{
    long num_inversions=0;
    if(low<high)
    {

        int mid=low+((high-low)>>1);
        num_inversions+=count_inversions_fast(arr,scratch,low,mid-1);
        num_inversions+=count_inversions_fast(arr, scratch,mid+1,high);
        int i=low, j=mid+1;

        for(int k=low;k<=high;++k)
        {
            if(i<=mid&&(j>high||arr[i]<=arr[j]))
            {
                scratch[k]=arr[i++];
            }else{
                num_inversions+=1;
                scratch[k]= arr[j++];
            }
        }
        for(int k=low;k<=high;k++)
        {
            arr[k]=scratch[k];
        }
    }
    return num_inversions;
}

int main(int argc, char *argv[])
{
// TODO: parse command-line argument

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
            int length=values.size();
            int *scratch = new int[length];

            // if slow command line specification, call slow counter
            cout << "Number of inversions: " << count_inversions_fast(values, scratch, 0, length-1) << endl;
                return 0;
            }
        }
    ///////////

    return 0;
}
