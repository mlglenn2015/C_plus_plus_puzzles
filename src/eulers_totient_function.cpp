#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
From http://www.crazyforcode.com/c-programs/

Euler’s Totient Function

In number theory, Euler’s totient function (or Euler’s phi function), denoted as φ(n) or ϕ(n), is
an arithmetic function that counts the positive integers less than or equal to n that are relatively
prime to n , i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1. (These integers are
sometimes referred to as totatives of n.)
*/

int phi (int n)
{
    int result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

string toString(int n)
{
	if (n != static_cast<int>(n)) {
	    cout << "n is not a number" << endl;
	    return "";
	} else {
	    return std::to_string(n);
	}
}

int main()
{
   cout << "phi(1) = " + toString(phi(1)) << endl;
   cout << "phi(2) = " + toString(phi(2)) << endl;
   cout << "phi(3) = " + toString(phi(3)) << endl;
   cout << "phi(4) = " + toString(phi(4)) << endl;
   cout << "phi(5) = " + toString(phi(5)) << endl;
   cout << "phi(6) = " + toString(phi(6)) << endl;
   cout << "phi(7) = " + toString(phi(7)) << endl;
   cout << "phi(8) = " + toString(phi(8)) << endl;
   cout << "phi(9) = " + toString(phi(9)) << endl;
   cout << "phi(10) = " + toString(phi(10)) << endl;

   return 0;
}

/* OUTPUT:
sh-4.3$ g++ -std=c++11 -o main *.cpp
sh-4.3$ main
phi(1) = 1
phi(2) = 1
phi(3) = 2
phi(4) = 2
phi(5) = 4
phi(6) = 2
phi(7) = 6
phi(8) = 4
phi(9) = 6
phi(10) = 4
*/
