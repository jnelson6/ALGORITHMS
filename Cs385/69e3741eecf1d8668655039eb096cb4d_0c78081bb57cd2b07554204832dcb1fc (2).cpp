/*******************************************************************************
 * Name    : waterjugpuzzle.cpp
 * Author  : J N
 * Date    : October 17, 2018
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

// code from simple State file given
// Struct to represent state of water in the jugs.
struct State {
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



/**** ******
	
	no solution output? 
	cout << "Initial State." << start.to_string() << endl;

	*
	*	Display output correctly (from main function?)
	*
	*	Correctly output 'No solution.' when there is none 
	*
	*	Working through Breadth First search 
	*
	*	Use valgrind to check all paths of code for memory leaks.  
	*		-when there is a solution, 
	*		-when there is no solution, and 
	*		-when the command line arguments don't validate.  
*/



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
        
        int visited[100][100][100];
        int i,j,k,p,q,r;
        
        for(i=0;i<100;i++)for(j=0;j<100;j++)for(k=0;k<100;k++)visited[i][j][k]=0;

		State start(A,B,C);	//start state
		State goal(a,b,c);	//stop state
		
        
        queue < State > qu;
        State initial(0,0,C);
        initial.directions.push_back("Initial state. "+initial.to_string());
        
        qu.push(initial);
        
        State temp(0,0,0);
        
        while(qu.size()>0){
        	temp=qu.front();
        	
        	qu.pop();
        	
        	if(visited[temp.a][temp.b][temp.c]==1)continue;
        	
        	visited[temp.a][temp.b][temp.c]=1;
        	
        	if(temp.a==a && temp.b==b && temp.c==c){
        		vector <string> vec=temp.directions;
        		for(i=0;i<vec.size();i++)cout << vec[i]<<endl;
        		return 1;
			}
        	
        	//Empty A
        	if(temp.a>0){
        		if(temp.a+temp.b<=B){
        			State tp(0,temp.a+temp.b,temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.a)+" gallons "+"from A to B. "+tp.to_string());
        			qu.push(tp);
				}
				
				else {
					State tp(temp.a-(B-temp.b),B,temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((B-temp.b))+" gallons "+"from A to B. "+tp.to_string());
        			qu.push(tp);
				}
				
				if(temp.a+temp.c<=C){
        			State tp(0,temp.b,temp.a+temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.a)+" gallons "+"from A to C. "+tp.to_string());
        			qu.push(tp);
				}
				
				else{
					State tp(temp.a-(C-temp.c),temp.b,C);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((C-temp.c))+" gallons "+"from A to C. "+tp.to_string());
        			qu.push(tp);
				}
			}
			
			if(temp.b>0){
				
				if(temp.b+temp.a<=A){
        			State tp(temp.a+temp.b,0,temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.b)+" gallons "+"from B to A. "+tp.to_string());
        			qu.push(tp);
				}
				
				else{
					State tp(A,temp.b-(A-temp.a),temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((A-temp.a))+" gallons "+"from B to A. "+tp.to_string());
        			qu.push(tp);
				}
				
				if(temp.b+temp.c<=C){
        			State tp(temp.a,0,temp.b+temp.c);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.b)+" gallons "+"from B to C. "+tp.to_string());
        			qu.push(tp);
				}
				
				else{
					State tp(temp.a,temp.b-(C-temp.c),C);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((C-temp.c))+" gallons "+"from B to C. "+tp.to_string());
        			qu.push(tp);
				}
			}
			
			if(temp.c>0){
				
				if(temp.c+temp.a<=A){
        			State tp(temp.a+temp.c,temp.b,0);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.c)+" gallons "+"from C to A. "+tp.to_string());
        			qu.push(tp);
				}
				
				else{
					State tp(A,temp.b,temp.c-(A-temp.a));
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((A-temp.a))+" gallons "+"from C to A. "+tp.to_string());
        			qu.push(tp);
				}
				
				if(temp.b+temp.c<=B){
        			State tp(temp.a,temp.b+temp.c,0);
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string(temp.c)+" gallons "+"from C to B. "+tp.to_string());
        			qu.push(tp);
				}
				
				else{
					State tp(temp.a,B,temp.c-(B-temp.b));
        			tp.directions=temp.directions;
        			tp.directions.push_back("Pour "+to_string((B-temp.b))+" gallons "+"from C to B. "+tp.to_string());
        			qu.push(tp);
				}
			}
        	
		}
		
		cout << "No solution."<<endl;
		return 0;
        
	}	
}











