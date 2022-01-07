//This program demonstrates using the C++ time function
//to provide a nseed,T for the random number generator.
#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
using namespace std;
int main()
{
    unsigned seed;  // Random generator seed
    // Use the time function to get a "seed¡± value for srand
    seed = time(0);
    srand(seed);
    // Now generate and print three random numbers
    cout << rand() << " " ;
    cout << rand() << " " ;
    cout << rand() << endl;
    return 0;
}
