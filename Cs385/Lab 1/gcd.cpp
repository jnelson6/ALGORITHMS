/*******************************************************************************
 * Name    : gcd.cpp
 * Author  : Julia Nelson
 * Version : 1.0
 * Date    : August 30, 2019
 * Description : Computes the GCD of two command-line arguments.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


/**
* Iteratively computes the GCD of two command-line arguments
*
*/
int gcd_iterative(int m, int n){
	int gcd_it;
	if (m == 0 || n == 0){			
		if (m ==0 && n == 0){		// if both inputs are 0, return 0
			return 0;				
		}
		return 1;					// if only one input is 0, return 1
	}
	for (int i = 1; i <= abs(m) && i<= abs(n); i++){	// abs() used for negative arguments
		if(m % i == 0 && n % i ==0 ){					
			gcd_it = i;
		}
	}
	return 	gcd_it;
}


/**
* Recursively computes the GCD of two command-line arguments
*
*/
int gcd_recursive(int m, int n){
	n = abs(n);						// abs() used for negative arguments
	m = abs(m);
	if (n == 0){					// when one of the inputs = 0 return the other input
		int gcd_re = m;
				return gcd_re;
	}
	if (m == 0){
		int gcd_re = n;
				return gcd_re;
	}
	if (m > n){								// when m > n , switch the modulo computation on the inputs
		return gcd_recursive(m % n, n);
	} 
	return gcd_recursive(m, n % m);
}

	
	

int main(int argc, char* const argv[]){

	/**** Following code used from CS385 practice.cpp file ****/
	int m, n;
    istringstream iss;

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>"
             << endl;
        return 1;
    }
    iss.str(argv[1]);
    if ( !(iss >> m) ) {
        cerr << "Error: The first argument is not a valid integer."
             << endl;
        return 1;
    }
    iss.clear(); // clear the error code
    iss.str(argv[2]);
    if ( !(iss >> n) ) {
        cerr << "Error: The second argument is not a valid integer."
             << endl;
        return 1;
    }
    /**** End cited code ****/

	cout <<  "Iterative: gcd(" << m  << ", "  << n << ") = " << gcd_iterative(m,n) << endl;
	cout <<  "Recursive: gcd(" << m << ", "  << n << ") = " << gcd_recursive(m,n) << endl; 
	return 0;
}
