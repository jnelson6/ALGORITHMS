/** 
* test.cpp
* January 27, 2020
* incla
* takes in 2 doubles from command line and finds the maximum
*
**/
#include <iostream>
#include <sstream>

using namespace std;



double max(double a, double b){
	return a > b ? a : b;		// is a > b ? .. return a... else return b
}


int main(int argc, char *argv[]){
	double m, n;
	istringstream iss;

	if (argc != 3){
		//if not give 3 args 
		cerr << "Usage: " << argv[0] << " <double m> <double n>" << endl;
		return 1; 
	}

	iss.str(argv[1]);
	if ( !(iss >> m) ){
		// lets convert iss into double m, if not successful execute this code
		cerr << "Error: The first argument is not a valid double." << endl;
		return 1;
	}

	iss.clear();
	iss.str(argv[2]);
		if ( !(iss >> n) ){
			// lets convert iss into double n, if not successful execute this code
			cerr << "Error: The second argument is not a valid double." << endl;
			return 1;
	}	


	cout << "max(" << m << ", " << n << ") = " << max(m, n) << endl;
	return 0;
}