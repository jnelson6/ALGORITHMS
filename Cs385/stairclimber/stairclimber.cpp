/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Julia Nelson
 * Date        : September 29, 2019
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

/**************************

TO GET FAMILIAR WITH APPRACH USE THIS .py CODE

"""
Basic (not most efficient) algorithm for generating all ways to
climb n stairs, going up 1, 2, or 3 stairs at a time.

Last modified: February 19, 2019
"""
def get_ways(num_stairs):
    ways = []
    if num_stairs <= 0:
        ways.append([])
    else:
        for i in range(1, 4):
            if num_stairs >= i:
                result = get_ways(num_stairs - i)
                for j in range(len(result)):
                    result[j].insert(0, i)
                ways += result
    return ways

for way in get_ways(4):
    print(way)

**************************/



    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
vector< vector<int> > get_ways(int num_stairs) {
    vector< vector<int> > ways;
    vector< vector<int> > result;
    
    if (num_stairs <= 0) {
        // if num_stairs is <= 0 push an empty vector into ways
        // since there is no way to climb 0 stairs
        vector<int> empty;
        ways.push_back(empty);
    }
    else {
        // else for each possibility of steps 1-3
        for (int i=1; i<4; i++) {
            if (num_stairs >= i) {
                // recusrsively call get_ways to get result of number of ways of climbing n-step stairs
                result = get_ways(num_stairs - i);
                for (auto it=result.begin(); it != result.end(); it++) {
                    // insert step into each result
                    (*it).insert((*it).begin(), i);
                    // push back result in ways vector
                    ways.push_back(*it);
                }
            }
        }
    }
    // return ways
    return ways;
}


    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
void display_ways(const vector< vector<int> > &ways) {
    int digits = 0;
    // find the max number of digits to dispaly way index
    for (int n=ways.size(); n!=0; digits++)
        n /= 10;
    
    // iterate over each way and display as a list [a, b, c,... ]
    for (unsigned int i=0; i<ways.size(); i++) {
        cout << setw(digits) << (i+1) << ". [";
        for (auto it=ways[i].begin(); it != ways[i].end(); it++) {
            cout << *it;
            if (it != ways[i].end()-1)
                cout << ", ";
        }
        if (i != ways.size()-1)
            cout << "]" << endl;
        else
            cout << "]";
    }
}


int main(int argc, char * const argv[]) {
    vector< vector<int> > ways;
    
    // check for valid number of arguments
    if (argc != 2) {
        cout << "Usage: ./stairclimber <number of stairs>";
        return 1;
    }
    // get number of stairs to climb
    int num_stairs = atoi(argv[1]);
    // check for valid number of stairs
    if (num_stairs <= 0) {
        cout << "Error: Number of stairs must be a positive integer.";
        return 1;
    }
    
    // get the ways of climbing the stairs
    ways = get_ways(num_stairs);
    
    // print summary of ways
    if (ways.size() == 1)
        cout << "1 way to climb ";
    else
        cout << ways.size() << " ways to climb ";
    if (num_stairs == 1)
        cout << "1 stair." << endl;
    else
        cout << num_stairs << " stairs." << endl;
    // display ways
    display_ways(ways);
    
    return 0;
}

