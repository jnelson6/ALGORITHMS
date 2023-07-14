#include <iostream>

using namespace std;


void display_array(int array[], const int length){
	cout << "[";
	if (length > 0){
		cout << array[0];
	}
	for (int i = 1; i < length; i++){
		cout << ", " << array[i];
	}
	cout << "]" << endl;
}




//using pointer arithmatic (same thing as above)

void display_array_ptr(int array[], const int length){
	cout << "[";
	if (length > 0){
		cout << *array;
	}
	for (int *ptr = array + 1, *end = array + length; ptr < end; ptr++){
		cout <<  ", " << *ptr;
	}
	cout << "]" << endl;
}


void pass_by_value(int x ){
	x = 10;

}

void pass_by_pointer(int *x){
	*x = 10;
}

void pass_by_reference(int &x){
	x = 10;
}

int main(){
	int x = 5, y = 6, *z = &x;
	cout << z << endl;
	cout << *z << endl;
	cout << "&x = " << &x << ", &y = " << &y << endl;
	cout << "&z = " << &z << endl;
	*z = 7;

	cout << "x = " << x << ", y = " << y << endl;
	z = &y;
	*z = 7;
	cout << "x = " << x << ", y = " << y << endl;


	cout << z << endl;
	cout << ++z << endl;


	 //z += 30000;
	 *z = 20;

	 int* values = new int[y];
	 for (int i = 0; i < y; i++){
	 	values [i] = i;
	 }

	 display_array(values, y);

	 display_array_ptr(values, y);
	 delete [] values; // frees up memory after allocating on the heap
	 

	 x = 5;
	 y = 6;
	 pass_by_value(x);
	 cout << "x = " << x << ", y = " << y << endl;
	 // doesnt modify the value of x


	 // both below modify X but the PREFFERED is pass_by_REFERENCE if you can 
	 // because you can modify the value but you cant have it refer to an entirely 
	 // different object.. cant point the pointer to someone else but you can reference 
	 // someone else so use reference. 

	 /// if you absolutely dont want to modify the reference use const in the begining of 
	 // the method so you dont accidentally mutate the value

	 x = 5;
	 y = 6;
	 pass_by_pointer(&x);
	 cout << "x = " << x << ", y = " << y << endl;
	 // this one modifies value of x to 10


 	 x = 5;
	 y = 6;
	 pass_by_reference(x);
	 cout << "x = " << x << ", y = " << y << endl;
	 // this one modifies value of x to 10


	return 0;
}









