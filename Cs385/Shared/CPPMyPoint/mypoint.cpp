// MAKE MY OWN OBJECTS

#include <iostream>
#include <iomanip>
#include <vector>			


using namespace std;

class MyPoint {

public:
	// everything after this is public

	// make a constructor that uses an initializer list
	MyPoint(int x, int y, float z) : x_{x}, y_{y}, z_{z} { }		//also helps range check 
					// initialize the member variables of the super class before the sub class
					// Initilized list MUST BE DECLARED IN ORDER THEY ARE USED

	~MyPoint(){
	//	cout << "Destructor called." << endl;
	}


	// Methods that do NOT modify the member variable should be declared  as CONST
	// 
	void print_coords() const {
		cout << "(x, y, z) = (" << x_ << ", " << y_ << ", " << fixed 
		<< setprecision(2) << z_ << ")" << endl;
	}

	// Accessor/Getter
	int get_x() const{
		//x_;
		return x_;
	}

	// Mutator/Setter	- not const because it mutates it
	void set_x(int x){
		x_ = x;
	}



private:
	int x_, y_;
	float z_;
};	// when done with a CLASS you need a ; and }

void display_points(const vector<MyPoint> &points) {
	for (auto it = points.cbegin(); it != points.cend(); ++it){		// collections class (it map string) do a PRE incriment not a POST
		it -> print_coords();

	}
}


int main(){


	MyPoint point1(5, 7.7, 1.24);
	MyPoint point2(1, 2, 3);
	MyPoint point3(4, 5, 6);

	vector<MyPoint> points;
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);

	vector<MyPoint> points_above_two;
	for ( const auto &point : points){				// can 'auto' deduce the type --- auto reference points - const so i dont mutates
		if (point.get_x() >2){
			points_above_two.push_back(point);
		}
	}

	display_points(points_above_two);

	
	cout << "Input x: ";
	cin >> x;

	cout << "Input y: ";
	cin >> y;
	int *x;1
	MyPoint *point4 = new MyPoint(x, y, 7);
	point4 -> print_coords();
	delete point4;


	return 0;
}





































