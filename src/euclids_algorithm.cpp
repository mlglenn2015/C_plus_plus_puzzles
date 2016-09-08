
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
From http://www.crazyforcode.com/c-programs/

Euclid’s Algorithm (Greatest Common Divisor) – GCD

Given two non-negative integers a and b. We need to find their greatest common divisor (GCD), ie,
the largest number that divides both a and b.

When it is of the numbers is zero, and the other is non-zero, their greatest common divisor, by
definition, it is the second number. When both numbers are zero, the result is not defined (any
suitable infinite number), we assume in this case the greatest common divisor of zero. Therefore,
we can speak of such a rule: if one of the numbers zero, their greatest common divisor is equal to
the second number.
Euclid’s algorithm , discussed below, solves the problem of finding the greatest common divisor of
two integers a and b over O(log min(a,b)).
This algorithm was first described in the book of Euclid’s “Elements” (about 300 BC), although it
is possible that the algorithm has an earlier origin.
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

//Greatest Common Denominator function
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

//Least Common Multiplier function
int lcm (int a, int b) {
    return a / gcd (a, b) * b;
}

int main()
{
   cout << "Listing Greatest Common Denominator examples:" << endl;
   cout << "gcd(1,1) = " + toString(gcd(1,1)) << endl;
   cout << "gcd(5,3) = " + toString(gcd(5,3)) << endl;
   cout << "gcd(6,3) = " + toString(gcd(6,3)) << endl;
   cout << "gcd(4,8) = " + toString(gcd(4,8)) << endl;
   cout << "gcd(70,100) = " + toString(gcd(70,100)) << endl;
   cout << "gcd(21,49) = " + toString(gcd(21,49)) << endl;
   cout << endl;
   cout << "Listing Least Common Multiplier examples:" << endl;
   cout << "lcm(21,49) = " + toString(lcm(21,49)) << endl;       //gcd(21,49)=7; 21/7=3; 3*49=147

   return 0;
}

/* OUTPUT:

Listing Greatest Common Denominator examples:
gcd(1,1) = 1
gcd(5,3) = 1
gcd(6,3) = 3
gcd(4,8) = 4
gcd(70,100) = 10
gcd(21,49) = 7

Listing Least Common Multiplier examples:
lcm(21,49) = 147

*/


