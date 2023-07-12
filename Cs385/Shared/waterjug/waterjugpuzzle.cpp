/*******************************************************************************
 * Name    : waterjugpuzzle.cpp
 * Author  : Julia Nelson
 * Date    : March 15, 2020
 * Description : Water Jug Puzzle using BFS
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






/*
*	I did Not work with a partner. 
*	Cited Code: (I don't believe this should be a problem? - just making sure)
*		I borrowed similar logic/initial arguments for my main function from my 
*			solo attempt at this assignment last semester. I found that to be my 
*			only solution of those arguments that I could get to work
*   I wrote a totally new (and hopefully improved) "else{ " code solution 
*/
int main(int argc, char* const argv[]) {
    if (argc != 7) {
        cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }
	for(int i = 1; i < 7; i++ ){		// 7 indices
		int value;
		istringstream iss(argv[i]);
		if( i == 1 && ( !(iss >> value) || value < 0) ){		// checks if non-neg int
				cerr << "Error: Invalid capacity '" << argv[i] << "' for jug A." << endl;
				return 1;
		}
		if( i == 2 && ( !(iss >> value) || value < 0 )  ){
			cerr << "Error: Invalid capacity '" << argv[i] << "' for jug B." << endl;
			return 1;
		}
		if( i == 3  && ( !(iss >> value) || value <= 0 ) ){		// Jug C cap can't = 0, checks if pos non-zero int
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
		
	int A,B,C,a,b,c;

	istringstream issA(argv[1]);
	;issA >> A;					//   ->>>>  ;issA >> A; ????
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

	// goal  greater than cap
	if( a > A){		
		cerr << "Error: Goal cannot exceed capacity of jug A." << endl;
		return 1;
	}
	if( b > B){
		cerr << "Error: Goal cannot exceed capacity of jug B." << endl;
		return 1;
	}
	if( c > C){
		cerr << "Error: Goal cannot exceed capacity of jug C." << endl;
		return 1;
	}
	if (C != a + b + c){
		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
		return 1;
	}

	// end code sampling from my previous code attempt





	else{
        int visited[100][100][100];
        int i;
        int j;
		int k;
        
        for(i = 0; i < 100; i++ ){
        	for( j = 0; j < 100; j++ ){
        		for( k = 0; k < 100; k++ ){
        			visited[i][j][k] = 0;
        		}
        	}
        }

		State start(A,B,C);					//start state
		State goal(a,b,c);					//stop state
		
        
        queue < State > queue1;
        State initial(0,0,C);
        initial.directions.push_back( "Initial state. " + initial.to_string() );			// push_back initial state on directions and print
        
        queue1.push(initial);		// push initial state onto queue
        
        State temp(0,0,0);			// set temp state
        
        while(queue1.size() > 0){
        	temp = queue1.front();
        	queue1.pop();
        	
        	if( visited[temp.a][temp.b][temp.c] == 1){
        		continue;			// breaks 1 iteration of loop (info on how to use found on w3schools.com cpp_break)
        	}
        	
        	visited[temp.a][temp.b][temp.c] = 1;
        	
        	if( (temp.a == a) && (temp.b == b) && (temp.c == c) ){
        		vector <string> vector1 = temp.directions;			// vector = temp's vector
        		for( i = 0; i < (long)vector1.size(); i++ ){
        			cout << vector1[i] << endl;
        		}
        		return 1;
			}
        	

							

        	//Empty A
        	if( temp.a > 0 ){

        		if( (temp.a + temp.b) <= B ){
        			State toPrint(0, (temp.a + temp.b), temp.c);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.a == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.a) + t + "from A to B. " + toPrint.to_string() );
        			queue1.push(toPrint);
				}
				
				else {
					State toPrint( (temp.a - (B - temp.b)), B, temp.c);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (B - temp.b) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (B - temp.b) ) + t + "from A to B. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				if( (temp.a + temp.c) <= C){
        			State toPrint(0, temp.b, (temp.a + temp.c) );
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.a == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.a) + t + "from A to C. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				else{
					State toPrint( (temp.a - (C - temp.c) ), temp.b, C);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (C - temp.c) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (C - temp.c) ) + t + "from A to C. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
			}
			//Empty B
			if(temp.b > 0){
				
				if((temp.b + temp.a) <= A){
        			State toPrint((temp.a + temp.b), 0, temp.c);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.b == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.b) + t + "from B to A. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				else{
					State toPrint( A,(temp.b - (A - temp.a)), temp.c);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (A - temp.a) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (A - temp.a) ) + t + "from B to A. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				if((temp.b + temp.c) <= C){
        			State toPrint( temp.a, 0, (temp.b + temp.c));
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.b == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.b) + t + "from B to C. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				else{
					State toPrint( temp.a, (temp.b - (C - temp.c)), C);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (C - temp.c) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (C - temp.c) ) + t + "from B to C. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
			}
			//Empty C
			if(temp.c > 0){
				
				if( (temp.c + temp.a) <= A){
        			State toPrint( (temp.a + temp.c), temp.b, 0);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.c == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.c) + t + "from C to A. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				else{
					State toPrint( A, temp.b, (temp.c - (A - temp.a)) );
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (A - temp.a) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (A - temp.a) ) + t + "from C to A. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				if( (temp.b + temp.c) <= B){
        			State toPrint(temp.a, (temp.b + temp.c), 0);
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( temp.c == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string(temp.c) + t + "from C to B. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
				
				else{
					State toPrint( temp.a, B, (temp.c - (B - temp.b)) );
        			toPrint.directions = temp.directions;
        			// deals with plurals
        			string t = " gallons ";
					if ( (B - temp.b) == 1){
						t = " gallon ";
					}
        			toPrint.directions.push_back( "Pour " + to_string( (B - temp.b) ) + t + "from C to B. " + toPrint.to_string());
        			queue1.push(toPrint);
				}
			}
        	
		}
		cout << "No solution." << endl;
		return 0;
        
	}	
}





