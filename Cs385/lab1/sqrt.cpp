/*******************************************************************************
 * Name    : sqrt.cpp
 * Author  : Julia Nelson
 * Version : 1.0
 * Date    : January 29, 2020
 * Description : Computes the square root of a double using Newton's method.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;



double sqrt(double num, double epsilon){

	if ( num == 0 || num == 1){										// Return num, if num is 0 or 1.
		return num;
	}

	if (num < 0){													// Return numeric_limits<double>::quiet_NaN(), if the num < 0. 
		return numeric_limits <double> :: quiet_NaN();				// This constant is found in the limits header.
	}
	
	else{
		double last_guess = num;
		double next_guess = (last_guess + (num / last_guess)) / 2; 

		while ( abs(last_guess - next_guess) > epsilon){			// Repeat next_guess = (last_guess + num/last_guess) / 2 until 
			last_guess = next_guess;								// abs(last_guess - next_guess) <= epsilon.
			next_guess = (last_guess + (num / last_guess)) / 2;
		
			if ( abs(last_guess - next_guess) <= epsilon){
				return next_guess;									// return the last value of next_guess.
			}
		}
		
		return next_guess;
	}
}


	// Takes in either one or two command line arguments, both of which are doubles.
	// The first argument is required... the number of which to take the square root.  
	// The second argument is optional... It is the value of epsilon, the amount by which 
	// the abs(last_guess - next_guess) is allowed to differ.  
int main(int argc, char *argv[]){
	double num, epsilon;
	istringstream iss;
	
	if ( argc != 2 && argc != 3 ) {
		cerr << "Usage: " << argv[0] << " <value> [epsilon]" << endl;
		return 1;
	}

	if (argc == 2){					// if epsilon is not given
		iss.str(argv[1]);
		if ( !(iss >> num) ){
			cerr << "Error: Value argument must be a double." << endl;
			return 1;
		}

		iss.clear();
		epsilon = 1e-7;		// If no argument is supplied, epsilon should be set to 1e-7, which is 10-7.
	}

	if (argc == 3){					// if epsilon is  given
		iss.str(argv[1]);
		if ( !(iss >> num) ){
			cerr << "Error: Value argument must be a double." << endl;
			return 1;
		}

		iss.clear();
		iss.str(argv[2]);
		if ( !(iss >> epsilon) ){
			cerr << "Error: Epsilon argument must be a positive double." << endl;
			return 1;
		}	
	}

	if ( epsilon <= 0){
		cerr << "Error: Epsilon argument must be a positive double." << endl;
		return 1;
	}
	
	double x = sqrt(num, epsilon);
	cout << fixed;
	cout << setprecision(8) << x << endl;
	return 0;	
}
	





