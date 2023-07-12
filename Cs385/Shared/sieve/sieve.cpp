/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Julia Nelson
 * Date        : 02/10/2020
 * Description : Sieve of Eratosthenes - finds prime numbers
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}


// Displays prime numbers found by Sieve of Eratosthenes according to document
void PrimesSieve::display_primes() const {

    
    cout << endl;   // extra line to match test file

    cout << "Number of primes found: " << count_num_primes() << endl;  
    cout << "Primes up to " << limit_ << ":" << endl;

    int max_prime_;
    for( int i = 0; i <= limit_; i++){      // finds the max prime  to set max_prime_
        if(is_prime_[i]){
            max_prime_ = i;
        }
    }
    
    const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1); // FROM DIRECTIONS

    int linecount = 1;      // helps keep track of numbers printed per line
    int num_primes_ = count_num_primes();
    if(num_primes_ <= primes_per_row) {
        for(int i = 0; i <= limit_; i++) {
            if(i < max_prime_){
                if( is_prime_[i]) {
                    cout << i << " "; 
                }
            }

            if( max_prime_ == i ){
                cout << i;
            }
        }
    }
    else{  //  right allign to width of max_prime_ if > 80
        for( int k = 2; k <= limit_; k++) {
            if( is_prime_[k] != false){
                if( primes_per_row != linecount) {
                    if( k == max_prime_) {
                        cout << setw(max_prime_width) << k;
                        linecount++;
                    }
                    else{
                        cout << setw(max_prime_width) << k << " ";
                        linecount++;
                    }
                }

                else{ // when k is max prime width

                    cout << setw(max_prime_width) << k << endl;
                    linecount = 1;
                }
            }
        }
    }

    cout << endl;

}





// Counts the number of primes found
int PrimesSieve::count_num_primes() const {
    
    int pcounter = 0;

    for(int i = 0; i <= limit_; i++) {
        if(is_prime_[i]){
            ++pcounter;             
        }
    }

    return pcounter;
}






// Sieve of Eratosthenes
// input n = limit_ ; n> 1
// Boolean array is_prime indices >2 set to TRUE 
void PrimesSieve::sieve() {
    for( int i = 2; i <= limit_; i++) {
        is_prime_[i] = true;
    }
    is_prime_[0] = false;
    is_prime_[1] = false;

    for( int i = 2; i <= sqrt(limit_); i++) {
        if(is_prime_[i] != false) {             // if it is true
            for (int k = i * i; k <= limit_; k += i){
                is_prime_[k] = false;           // not a prime 
            }
        }
    }

    count_num_primes();
    
}




// Determines how many digits are in an integer
// (No strings  needed. Keep dividing by 10.)
int PrimesSieve::num_digits(int num) {
    int digits = 0;
    while( num >= 1) {  // continuously divides by 10
        num /= 10;
        digits++;         
    }

    return digits;
}




int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    PrimesSieve primeNumbers(limit);
    primeNumbers.display_primes();

    return 0;
}
