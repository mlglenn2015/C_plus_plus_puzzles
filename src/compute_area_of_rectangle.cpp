// Example program
#include <iostream>
#include <string>

using namespace std;


bool isNumericInteger(int n)
{
	if (n != static_cast<int>(n)) {
	    return false;
	}
	return true;
}

int main()
{
    int len;
    int width;

    std::cout << "Input the length of the long side of the rectangle: ";
    std::cin >> len;

    /*if (!isNumericInteger(len)) {
       cout << "Error. The value must be a number greater than 0. Exiting ... ";
       return 1;
    }*/

    /*while (len <= 0) {
        cout << "Error: " << len << " must be greater than 0. Please input the length of the long side of the rectangle: ";
        std::cin >> len;
    }*/

    std::cout << "You input " << len << endl;


    std::cout << "Input the length of the short side of the rectangle: ";
    std::cin >> width;
    std::cout << "You input " << width << endl;

    if (len <= width) {
        cout << "Using " << width << " as the long side and " << len << " as the short side..." << endl;
        int temp = len;
        len = width;
        width = temp;
    }

    int area = len * width;
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
