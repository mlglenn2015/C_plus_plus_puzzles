#include <iostream>
//#include <array>
#include <cmath>
#include <string>
#include <exception>
#include <vector>

using namespace std;

/*
http://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
*/


//function to accept an array as an argument
double getAverage(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
  return double(sum) / size;
}

int getArrayLengthWithinLimit(int * arr) //accept array as argument
{
    int size=0;
    int imax=5000;
    cout << "arr: " << arr << endl;
    cout << "arr[0]: " << arr[0] << endl; //Returns value of first element in the array (1000)
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "sizeof(*(arr)): " << sizeof(*(arr)) << endl;
    //return ((sizeof(arr) / sizeof(*(arr))) / static_cast<size_t>(!(sizeof(arr) % sizeof(*(arr)))));

    /*try {
        for (int i=0; i<10; i++)
        {
            cout << "arr[" << i << "]: " << arr[i] << endl;
            //cout << "arr.at(" << i << "): " << arr.at(i) << endl;
            ++size;
        }
    } catch (const std::out_of_range& r) {
        //cout << "Exception caught: " << e.what() << endl;
        std::cout << "Something goes wrong: " << r.what() << std::endl;
    }*/

    return size;
}

int main()
{
    /**************************************************************************/
    //Illustrating use of passing an array of int as an argument to a function
    //that calculates the average of the numbers
    // an int array with 5 elements.
    int balance[6] = {1000, 2, 3, 17, 50, 19};
    int balanceSize = (sizeof(balance) / sizeof(*(balance)));
    double avg;
    // pass pointer to the array as an argument.
    avg = getAverage( balance, balanceSize );

    cout << "balance: " << balance << endl; //Returns address of first element in the array (0x7fffc3435870)
    cout << "*balance: " << *balance << endl; //Returns a pointer to the first element in the array (1000)
    cout << "&balance: " << &balance << endl; //Returns address of first element in the array (0x7fffc3435870)
    cout << "balance[0]: " << balance[0] << endl; //Returns value of first element in the array (1000)
    cout << "sizeof(balance): " << sizeof(balance) << endl;
    cout << "sizeof(*(balance)): " << sizeof(*(balance)) << endl;
    cout << "Number of elements in balance[]: " << balanceSize << endl;
    int testsize = getArrayLengthWithinLimit(balance);
    for (int i=0; i<balanceSize; i++)
    {
        cout << "balance[" << i << "]: " << balance[i] << endl; //Print the element
    }

    // output the returned value
    cout << "Average value of balance is: " << avg << endl;
    /* OUTPUT
    balance: 0x7fff506ca2d0
    *balance: 1000
    &balance: 0x7fff506ca2d0
    balance[0]: 1000
    sizeof(balance): 24
    sizeof(*(balance)): 4
    Number of elements in balance[]: 6
    arr: 0x7fff506ca2d0
    arr[0]: 1000
    sizeof(arr): 8
    sizeof(*(arr)): 4
    balance[0]: 1000
    balance[1]: 2
    balance[2]: 3
    balance[3]: 17
    balance[4]: 50
    balance[5]: 19
    Average value of balance is: 181.833
    */
    /**************************************************************************/

    return 0;
}

