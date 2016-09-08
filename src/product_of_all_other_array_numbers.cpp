
#include <array>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
From From http://www.crazyforcode.com/c-programs/

Product of All Other Array Numbers
April 16, 2016 11:47 am | 1 Comment | crazyadmin

Problem:
Given an array of n integers where n>1, return an array of same size an input array where at every
index of the output array should contain the product of all elements in the array except the element
at the given index.

Example:
arr[] = {10, 4, 1, 6, 2}
prod[] = {48,120,480,80,240}
*/

/*
Notes: C++ does not allow to return an entire array as an argument to a function.
However, you can return a pointer to an array by specifying the array's name
without an index.
*/
int * product_without_self(int arr[], int size) {  //also passing an array as an argument
    cout << "arr: " << arr << endl;
    cout << "arr size: " << size << endl;
    int newArray[size];

    newArray[size-1] = 1;
    for(int i=size-2; i>=0; i--) {
        newArray[i] = newArray[i+1] * arr[i+1];
    }
    int left = 1;
    for(int i=0; i<size; i++) {
        newArray[i] *= left;
        left *= arr[i];
    }
    cout << "newArray: " << newArray << endl;
    for(int i=0; i<size; i++) {
        cout << "newArray[" << i << "]: " << newArray[i] << endl;
    }
    return newArray;
}

int * product_without_self_by_reference(int arr[], int size, int returnArr[]) {  //also passing an array as an argument
    cout << "arr: " << arr << endl;
    cout << "arr size: " << size << endl;

    returnArr[size-1] = 1;
    for(int i=size-2; i>=0; i--) {
        returnArr[i] = returnArr[i+1] * arr[i+1];
    }
    int left = 1;
    for(int i=0; i<size; i++) {
        returnArr[i] *= left;
        left *= arr[i];
    }
    cout << "returnArr: " << returnArr << endl;
    for(int i=0; i<size; i++) {
        cout << "returnArr[" << i << "]: " << returnArr[i] << endl;
    }
    return returnArr;
}

int main()
{
    int myArray[5] = {10, 4, 1, 6, 2};
    int myArraySize = (sizeof(myArray) / sizeof(*(myArray)));
    cout << "main().myArray: " << myArray << endl;
    cout << "main().myArraySize: " << myArraySize << endl;

    //NOTE: accessing pArray will core dump because it was set to the address of a local variable no longer in scope
    int * p1Array = product_without_self(myArray, myArraySize);
    //cout << "main().p1Array: " << p1Array << endl;
    //cout << "main().p1Array[0]: " << p1Array[0] << endl;   // <-- CORE DUMP!

    //TRY THIS INSTEAD: Pass in a reference to the return array
    int myNewArray[myArraySize];
    int * p2Array = product_without_self_by_reference(myArray, myArraySize, myNewArray);
    cout << "main().myNewArray: " << myNewArray << endl;
    for(int i=0; i<myArraySize; i++) {
        cout << "myNewArray[" << i << "]: " << myNewArray[i] << endl;
    }

    //OR TRY THIS: Pass in a reference to the return array and set the return pointer to a local
    int myNewArray2[myArraySize];
    int * p3Array = product_without_self_by_reference(myArray, myArraySize, myNewArray2);
    cout << "main().myNewArray2: " << myNewArray2 << endl;
    for(int i=0; i<myArraySize; i++) {
        cout << "p3Array[" << i << "]: " << p3Array[i] << endl;
    }

    return 0;

    /* OUTPUT:
    main().myArray: 0x7ffedf5c7f20
    main().myArraySize: 5
    arr: 0x7ffedf5c7f20
    arr size: 5
    newArray: 0x7ffedf5c7e60
    newArray[0]: 48
    newArray[1]: 120
    newArray[2]: 480
    newArray[3]: 80
    newArray[4]: 240
    arr: 0x7ffedf5c7f20
    arr size: 5
    returnArr: 0x7ffedf5c7ed0
    returnArr[0]: 48
    returnArr[1]: 120
    returnArr[2]: 480
    returnArr[3]: 80
    returnArr[4]: 240
    main().myNewArray: 0x7ffedf5c7ed0
    myNewArray[0]: 48
    myNewArray[1]: 120
    myNewArray[2]: 480
    myNewArray[3]: 80
    myNewArray[4]: 240
    arr: 0x7ffedf5c7f20
    arr size: 5
    returnArr: 0x7ffedf5c7eb0
    returnArr[0]: 48
    returnArr[1]: 120
    returnArr[2]: 480
    returnArr[3]: 80
    returnArr[4]: 240
    main().myNewArray2: 0x7ffedf5c7eb0
    p3Array[0]: 48
    p3Array[1]: 120
    p3Array[2]: 480
    p3Array[3]: 80
    p3Array[4]: 240
    */
}

