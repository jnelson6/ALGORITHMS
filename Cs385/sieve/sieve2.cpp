/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Julia Nelson
 * Date        : 09/11/19
 * Description : a program that finds prime numbers using the Sieve of Eratosthenes
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

    inline int num_primes() const {
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
    int maxPrime() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}



/**
* Then finds primes up to and including that limit
* Then displays the numbers with 1 space b/w each(no space at end). 
* If multiple lines in output, right-align the numbers to width of largest prime. 
*/

void PrimesSieve::display_primes() const {

    int num_primes_ = count_num_primes();

    cout << endl;
    cout << "Number of primes found: " << num_primes_ << endl;
    cout << "Primes up to " << limit_ << ":" << endl;   
 

    int max_prime_ = maxPrime();
    const int max_prime_width = num_digits(max_prime_),              // POSSIBLE ; not ,
        primes_per_row = 80 / (max_prime_width + 1);
    int print_count_for_line = 1;
    // if num_primes_ is less than 80, display the prime numbers on one line 
    // with 1 space b/w each

    // cout << "max prime : " << max_prime_ << endl;

    if(num_primes_ <= primes_per_row){
        // cout << "Inside if\n";
        for( int i = 0; i <= limit_; i++){
            // cout << "Checking " << i << endl;
            if(is_prime_[i]){
                if( i < max_prime_){
                    cout << i << " " ;
                }
                if(i == max_prime_){
                    cout << i;
                }

            }
        }

    }

    // when num_primes_ is > 80, right allign to width of max_prime
    else{
        // cout << "Inside else\n";
        for (int j = 2; j <= limit_; j++){
            if( is_prime_[j] == true){
                if(print_count_for_line != primes_per_row){
                    if(j != max_prime_){
                        cout << setw(max_prime_width) << j << " ";
                        print_count_for_line++;
                    }
                    else{
                        cout << setw(max_prime_width) << j;
                        print_count_for_line++;
                    }
                }
                else{
                    cout << setw(max_prime_width) << j << endl;
                    print_count_for_line = 1;       // 1 because the max_prime takes of the whole line
                }
            }
        }       
    }
    cout << endl;
}



/**
* Helps find max prime (max_prime_ was not working out)
*/
int PrimesSieve::maxPrime() const
{
    int temp = 0;
    for( int i = 0; i <= limit_; i++){
        if(is_prime_[i]){
            temp = i;
        }
    }
    return temp;
}



/**
* iterates through numbers <= limit_ an checks if they are a prime num
* adds 1 to counter for each prime number found
*/
int PrimesSieve::count_num_primes() const {
    int count = 0;
    for( int i = 0; i <= limit_; i++){
        if(is_prime_[i]){
            count++;
        }
    }
    return count;
}



/**
* Takes input n > 1 which is limit_
* Sets all indexes > 2 of boolean array is_prime to true
*/
void PrimesSieve::sieve() {
   // Input: an integer n > 1

    // is_prime_ is an array of bool values...
    // all other indexes 2 to n set to true
    for(int i = 2; i <= limit_; i++){
        is_prime_[i] = true;
    }
    // index 0, 1 set to false
    is_prime_[0] = false;                                      
    is_prime_[1] = false;

   // for i = 2, 3, 4, ..., while i ≤ √𝑛:
    for(int i = 2; i <= sqrt(limit_); i++){
        //if is_prime[i] is true:
        if(is_prime_[i] == true){
             //for j = i2, i2 + i, i2 + 2i, ..., while j ≤ n:
            for(int j = i*i; j<= limit_; j += i){
                 //is_prime[j] = false (not a prime)
                is_prime_[j] = false;
            }
        }
    }
    count_num_primes(); // Now all i such that is_prime[i] is true are prime.          
}




/**
* determines how many digits are in integer num
* takes num if >=1 and divides by 10 
* then incriments num_digs by 1 to count the first digit
* repeats to count all digits
* No strings are needed. Keeps dividing by 10.
*/
int PrimesSieve::num_digits(int num) {
    // num_digs is the number of digits in int num
    int num_digs = 0;

    // if num >1 but less than 10, when /10 it counts one and stops because num now < 1
    // incriments num_digs by 1 to count the digit
    while(num >= 1){
        num /= 10;
        num_digs++;
    }
    return num_digs;
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
    PrimesSieve primeNums(limit);
    primeNums.display_primes();
    return 0;
}

























