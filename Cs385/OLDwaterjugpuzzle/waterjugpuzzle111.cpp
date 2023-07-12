/*******************************************************************************
 * Name    : waterjugpuzzle.cpp
 * Author  : Julia Nelson
 * Date    : March 15, 2020
 * Description : Solves the Water Jug Puzzle using BFS
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;


struct State {					// Given State Struct file code
    int A,B,C,a, b, c;
    vector<string> directions;									
    
    State(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }
    
    // String representation of state in tuple form.
    string to_string() {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
};







int main(int argc, char* const argv[]) {
	

    if (argc != 7) {
        cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }
    
    // seven indexes 
	for(int i = 1; i < 7; i++ ){
		
		int value;
		istringstream iss(argv[i]);

		// iss >> value checks that argument is an integer
		// value < 0 checks for negative arguments
		if( i == 1 && (!(iss >> value) || value < 0  )){
				cerr << "Error: Invalid capacity '" << argv[i] << "' for jug A." << endl;
				return 1;
		}

		if( i == 2 && ( !(iss >> value) || value < 0 )  ){
			cerr << "Error: Invalid capacity '" << argv[i] << "' for jug B." << endl;
			return 1;
		}

		// value <= 0 argument rather than < 0 because jug C Capacity cannot start at 0
		if( i == 3  && ( !(iss >> value) || value <= 0 ) ){
			cerr << "Error: Invalid capacity '" << argv[i] << "' for jug C." << endl;
			return 1;
		}

		if( i == 4  && ( !(iss >> value) || value < 0 ) ){
			cerr << "Error: Invalid goal '" << argv[i] << "' for jug A." << endl;
			return 1;
		}

		if( i == 5  && ( !(iss >> value) || value < 0 )  ){
			cerr << "Error: Invalid goal '" << argv[i] << "' for jug B." << endl;
			return 1;
		}

		if( i == 6  && ( !(iss >> value) || value < 0 ) ){
			cerr << "Error: Invalid goal '" << argv[i] << "' for jug C." << endl;
			return 1;
		}
	}
		
	int A;
	int B;
	int C;
	int a;
	int b;
	int c;

	istringstream issA(argv[1]);
	;issA >> A;
	istringstream issB(argv[2]);
	;issB >> B;
	istringstream issC(argv[3]);
	;issC >> C;
	istringstream issa(argv[4])
	;issa >> a;
	istringstream issb(argv[5]);
	;issb >> b;
	istringstream issc(argv[6]);
	;issc >> c;

	// if goal is great that capacity
	if( a > A){
		cerr << "Error: Goal cannot exceed capacity of jug A." << endl;
		return 1;
	}
	// if goal is great that capacity
	if( b > B){
		cerr << "Error: Goal cannot exceed capacity of jug B." << endl;
		return 1;
	}
	// if goal is great that capacity
	if( c > C){
		cerr << "Error: Goal cannot exceed capacity of jug C." << endl;
		return 1;
	}
	// if C is not = to total gallons
	if (C != a + b + c){
		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
		return 1;
	}


	else{



		State start(A,B,C);	//start state
		State goal(a,b,c);	//stop state
		

			State initial(0,0,C);
			cout << "Initial state. " << initial.to_string() << endl;		// print intial state
			
			//check if the current state is = to the goal
			if(initial.a == goal.a && initial.b == goal.b && initial.c == goal.c){
				return 0;
			}


		///////// Pour C to A
			if (goal.a > goal.b && initial.a < A && !(initial.c == 0)){
				initial.a += initial.c;
				if (initial.a > A){
					initial.a = A;
				}

				initial.c -= initial.a;
				State s1(initial.a,initial.b,initial.c);

				// fixes grammar for output
				string g = "gallons";
				if (s1.a == 1){
				g = "gallon";
				}
				cout << "Pour " << s1.a  << " " << g << " from C to A. " << s1.to_string() << endl;
				
				if(s1.a == goal.a && s1.b == goal.b && s1.c == goal.c){
					return 0;
				}

			//////////// Pour A to B
				if (goal.b > goal.a && s1.b < B && !(s1.a == 0)){
					s1.b += s1.a;
					if (s1.b > B){
						s1.b = B;
					}
					s1.a -= (s1.b - initial.b);
					State s2(s1.a,s1.b,s1.c);

					string g = "gallons";
					if ((s1.b - initial.b) == 1){
						g = "gallon";
					}
					cout << "Pour " << (s1.b - initial.b)  << " " << g << " from A to B. " << s2.to_string() << endl;
					if(s2.a == goal.a && s2.b == goal.b && s2.c == goal.c){
						return 0;
					}

				/// C to B
					if (s2.b < B && !(s2.c == 0)){
						s2.b += s2.c;
						if (s2.b > B){
							s2.b = B;
						}
						s2.c -= (s2.b - s1.b);
						State s3(s2.a,s2.b,s2.c);

						string g = "gallons";
						if ((s2.b - s1.b) == 1){
							g = "gallon";
						}
						cout << "Pour " << (s2.b - s1.b) << " " << g << " from C to B. " << s3.to_string() << endl;
						if(s3.a == goal.a && s3.b == goal.b && s3.c == goal.c){
							return 0;
						}
					

					// B to A
						if (s3.a < A && !(s3.b == 0)){
							s3.a += s3.b;
							if (s3.a > A){
								s3.a = A;
							}
							s3.b -= (s3.a - s2.a);
							State s4(s3.a,s3.b,s3.c);

							string g = "gallons";
							if ((s3.a - s2.a) == 1){
								g = "gallon";
							}
							cout << "Pour " << (s3.a - s2.a)  << " " << g << " from B to A. " << s4.to_string() << endl;
							if(s4.a == goal.a && s4.b == goal.b && s4.c == goal.c){
								return 0;
							}
						}

					}
				}

			///// B to A
				if (goal.a > 0 && s1.a < A && !(s1.b == 0)){
					s1.a += s1.b;
					if (s1.a > A){
						s1.a = A;
					}
					s1.b -= (s1.a - initial.a);
					State s2(s1.a,s1.b,s1.c);

					string g = "gallons";
					if ((s1.a - initial.a) == 1){
						g = "gallon";
					}
					cout << "Pour " << (s1.a - initial.a) << " " << g << " from B to A. " << s2.to_string() << endl;
					if(s2.a == goal.a && s2.b == goal.b && s2.c == goal.c){
						return 0;
					}
				}
			}


//////////////////////////////////////////////////

		// Pour C to B
			if (goal.a < goal.b && initial.b < B && !(initial.c == 0)){
				initial.b += initial.c;
				if (initial.b > B){
					initial.b = B;
				}
				initial.c -= initial.b;
				State s1(initial.a,initial.b,initial.c);

				string g = "gallons";
				if (s1.b == 1){
					g = "gallon";
				}
				cout << "Pour " << s1.b  << " " << g << " from C to B. " << s1.to_string() << endl;
				if(s1.a == goal.a && s1.b == goal.b && s1.c == goal.c){
					return 0;
				}

			// Pour B to A
				if (s1.a < s1.b && s1.a < A && !(s1.b == 0)){
					s1.a += s1.b;
					if (s1.a > A){
						s1.a = A;
					}
					s1.b -= (s1.a - initial.a);
					State s2(s1.a,s1.b,s1.c);

					string g = "gallons";
					if ((s1.a - initial.a) == 1){
						g = "gallon";
					}
					cout << "Pour " << (s1.a - initial.a) << " " << g << " from B to A. " << s2.to_string() << endl;
					if(s2.a == goal.a && s2.b == goal.b && s2.c == goal.c){
						return 0;
					}

					//Pour A to C
					if (s2.c < C && !(s2.A == 0)){
						s2.c += s2.a;
						if (s2.c > C){
							s2.c = C;
						}
						s2.a -= (s2.c - s1.c);
			
						State s3(s2.a,s2.b,s2.c);

						string g = "gallons";
						if ((s2.c - s1.c) == 1){
							g = "gallon";
						}
						cout << "Pour " << (s2.c - s1.c) << " " << g << " from A to C. " << s3.to_string() << endl;
						if(s3.a == goal.a && s3.b == goal.b && s3.c == goal.c){
							return 0;
						}

						// Pour B to A
						if (s3.a < s3.b && s3.a < A && !(s3.b == 0)){
							s3.a += s3.b;
							if (s3.a > A){
								s3.a = A;
							}
							s3.b -= (s3.a - s2.a);
							State s4(s3.a,s3.b,s3.c);

							string g = "gallons";
							if ((s3.a - s2.a) == 1){
								g = "gallon";
							}
							cout << "Pour " << (s3.a - s2.a) << " " << g << " from B to A. " << s4.to_string() << endl;
							if(s4.a == goal.a && s4.b == goal.b && s4.c == goal.c){
								return 0;
							}
							
						}	
						//POUR A to C
						if(s3.b == 1 && !(s3.a == 0) ){
							s3.c += s3.a;
							if (s3.c > C){
								s3.c = C;
							}
							s3.a -= (s3.c - s2.c);
				
							State s4(s3.a,s3.b,s3.c);

							string g = "gallons";
							if ((s3.c - s2.c) == 1){
								g = "gallon";
							}
							cout << "Pour " << (s3.c - s2.c) << " " << g << " from A to C. " << s4.to_string() << endl;
							if(s4.a == goal.a && s4.b == goal.b && s4.c == goal.c){
								return 0;
							}
							
						}
						
					}
					
				}
				
			}


		
	
		
		return 0;

	

	}	
}
	







		













