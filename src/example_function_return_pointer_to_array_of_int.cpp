

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
http://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm

Notes: C++ does not allow to return an entire array as an argument to a function.
However, you can return a pointer to an array by specifying the array's name
without an index.
*/

// function to generate and retrun random numbers.
int * getRandom()
{
  static int  r[10];

  // set the seed
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }

  return r;
}

int main()
{
    /**************************************************************************/
    // Printing random numbers illustrates the use of a function to return a
    // pointer to an array of ints
    int *p;   // a pointer to an int.
    p = getRandom();
    for ( int i = 0; i < 10; i++ )
    {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
    }
    /* OUTPUT
    160979092
    367328025
    1549694687
    2118439252
    1033446175
    1091088431
    575742325
    828003803
    236843440
    779738691
    *(p + 0) : 160979092
    *(p + 1) : 367328025
    *(p + 2) : 1549694687
    *(p + 3) : 2118439252
    *(p + 4) : 1033446175
    *(p + 5) : 1091088431
    *(p + 6) : 575742325
    *(p + 7) : 828003803
    *(p + 8) : 236843440
    *(p + 9) : 779738691
    */
    /**************************************************************************/

    return 0;
}

