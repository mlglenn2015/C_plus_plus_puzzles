
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
From http://www.crazyforcode.com/c-programs/

How to Check if a given Number is Fibonacci number?

In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following
integer sequence:

1,1,2,3,5,8,13,21,34,55,89,144..

A simple way is to generate Fibonacci numbers until the generated number is greater than or equal
to ‘x’. Following is an interesting property about Fibonacci numbers that can also be used to check
if a given number is Fibonacci or not.

The question may arise whether a positive integer x is a Fibonacci number. This is true if and only
if one or both of 5x^2+4 or 5x^2-4 is a perfect square. (Source: Wiki)
*/

string toString(int n)
{
	if (n != static_cast<int>(n)) {
	    cout << "n is not a number" << endl;
	    return "";
	} else {
	    return std::to_string(n);
	}
}

int returnPerfectSquare(int n)
{
    return (n*n);
}

//A perfect square is a number that is the product of a number times itself
//Example: 7*7 = 49, where 49 is a perfect square
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}

// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int x)
{
    return isPerfectSquare(5*x*x + 4) ||
           isPerfectSquare(5*x*x - 4);
}


//List perfect squares up to square root 20
void listPerfectSquares()
{
    for (int i=1; i<25; i++)
    {
        cout << "returnPerfectSquare(" + toString(i) + ") = " + toString(returnPerfectSquare(i)) << endl;
    }
}

//List some Fibonacci tests
void listFibonaccis()
{
    for (int i=1; i<25; i++)
    {
        cout << "isFibonacci(" + toString(i) + ") = " + (isFibonacci(i) ? "TRUE" : "FALSE") << endl;
    }
}

int main() {
    cout << "Testing numbers to see if perfect squares (1=True, 0=False):" << endl;
    cout << "isPerfectSquare(1) = " + toString(isPerfectSquare(1) ? 1 : 0) + " " + (isPerfectSquare(1) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(2) = " + toString(isPerfectSquare(2) ? 1 : 0) + " " + (isPerfectSquare(2) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(3) = " + toString(isPerfectSquare(3) ? 1 : 0) + " " + (isPerfectSquare(3) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(7) = " + toString(isPerfectSquare(7) ? 1 : 0) + " " + (isPerfectSquare(7) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(21) = " + toString(isPerfectSquare(21) ? 1 : 0) + " " + (isPerfectSquare(21) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(49) = " + toString(isPerfectSquare(49) ? 1 : 0) + " " + (isPerfectSquare(49) ? "TRUE" : "FALSE") << endl;
    cout << "isPerfectSquare(10) = " + toString(isPerfectSquare(10) ? 1 : 0) + " " + (isPerfectSquare(10) ? "TRUE" : "FALSE") << endl;
    cout << endl;

    cout << "Listing perfect squares:" << endl;
    listPerfectSquares();
    cout << endl;

    cout << "Listing Fibonacci tests:" << endl;
    listFibonaccis();
    cout << endl;

    return 0;
}

/* OUTPUT:
Testing numbers to see if perfect squares (1=True, 0=False):
isPerfectSquare(1) = 1 TRUE
isPerfectSquare(2) = 0 FALSE
isPerfectSquare(3) = 0 FALSE
isPerfectSquare(7) = 0 FALSE
isPerfectSquare(21) = 0 FALSE
isPerfectSquare(49) = 1 TRUE
isPerfectSquare(10) = 0 FALSE

Listing perfect squares:
returnPerfectSquare(1) = 1
returnPerfectSquare(2) = 4
returnPerfectSquare(3) = 9
returnPerfectSquare(4) = 16
returnPerfectSquare(5) = 25
returnPerfectSquare(6) = 36
returnPerfectSquare(7) = 49
returnPerfectSquare(8) = 64
returnPerfectSquare(9) = 81
returnPerfectSquare(10) = 100
returnPerfectSquare(11) = 121
returnPerfectSquare(12) = 144
returnPerfectSquare(13) = 169
returnPerfectSquare(14) = 196
returnPerfectSquare(15) = 225
returnPerfectSquare(16) = 256
returnPerfectSquare(17) = 289
returnPerfectSquare(18) = 324
returnPerfectSquare(19) = 361
returnPerfectSquare(20) = 400
returnPerfectSquare(21) = 441
returnPerfectSquare(22) = 484
returnPerfectSquare(23) = 529
returnPerfectSquare(24) = 576

Listing Fibonacci tests:
isFibonacci(1) = TRUE
isFibonacci(2) = TRUE
isFibonacci(3) = TRUE
isFibonacci(4) = FALSE
isFibonacci(5) = TRUE
isFibonacci(6) = FALSE
isFibonacci(7) = FALSE
isFibonacci(8) = TRUE
isFibonacci(9) = FALSE
isFibonacci(10) = FALSE
isFibonacci(11) = FALSE
isFibonacci(12) = FALSE
isFibonacci(13) = TRUE
isFibonacci(14) = FALSE
isFibonacci(15) = FALSE
isFibonacci(16) = FALSE
isFibonacci(17) = FALSE
isFibonacci(18) = FALSE
isFibonacci(19) = FALSE
isFibonacci(20) = FALSE
isFibonacci(21) = TRUE
*/
