#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define SUCCESS 0
#define FAILURE 1


struct SampleData
{
   int count;
   float frequency;
};

void printSampleData(vector<SampleData> counterVector)
{
   cout << "Digit     Count     Frequency \n";

   for(unsigned int i=0; i<counterVector.size(); ++i)
   {
	  //cout << "i=" << i << "..............  ";
	  //compute the frequency based on the count of each digit
	  // float frequency = counterVector[i] / numBase10Digits;
	  //float frequency = counterVector[i].count / numBase10Digits;
	  // cout << i+1 << "         " << counterVector[i] << "         " << fixed << setprecision(2) << frequency << endl;
	  //cout << i+1 << "         " << counterVector[i].count << "         " << fixed << setprecision(2) << frequency << endl;
	  cout << i+1 << "         " << counterVector[i].count << "         " << fixed << setprecision(2) << counterVector[i].frequency << endl;
   }
}

int main()
{
   string fileName;
   string inputLine;
   const float numBase10Digits = 10.0;
   const size_t numElems = 9;		//Vector containing 9 elements

   //vector<int> counterVector(numElems);
   //vector<int>::iterator iterator = counterVector.begin();

   //now instead of using a vector of int, we are using a vector of structures of type SampleData
   //struct SampleData mySampleData;
   vector<SampleData> counterVector(numElems);
   vector<SampleData>::iterator iterator = counterVector.begin();

   cout << "vector size = " << counterVector.size() << endl;

   ////// Begin //////
   cout << "Input the file name: ";
   getline (cin, fileName);
   cout << "You input " << fileName << " ...\n";

   /*
    1. Check for existence of file. If not found, exit
    */
   ifstream inFile (fileName);
   if (inFile.is_open())
   {
      //cout << "File " << fileName << " successfully opened, reading ... \n";

      /*
 	   2. Read input file, ignoring white space, comments and any line that starts with char 0. Load each line of data into the vector.
	   */
      while (getline(inFile, inputLine))
      {
         //cout << "\ninputLine: " << inputLine << endl;

		 int numericVal;
		 istringstream iss(inputLine);
		 iss >> numericVal;

		 cout << "numericVal: " << numericVal << endl;
		 cout << "********* Inspecting: " << numericVal << endl;
         cout << "********* First char : " << inputLine[0] << endl;  //We stored inputLine as a string so we can reference the first character here and assign to our array
		 int firstDigit = int(inputLine[0])-'0';
		 cout << "********* First digit: " << firstDigit << endl;

		 /*
          3. Iterate through the vector and write the output to the console, counting the occurrences of the first number in each entry.

          What we know:
             1. The assignment expects counts for integers 1 through 9. Some integers will have 0 for the count. We will count the occurrences of numbers 1 through 9.
             2. The output appears to be formatted into fixed-width columns
             3. The Frequency is a floating point decimal that can be computed as ratio of the total number of base-10 digits (0-9).

          Example Output:
          Digit     Count     Frequency
          1         3         0.30
          2         2         0.20
          3         2         0.20
          4         0         0.00
          5         0         0.00
          6         0         0.00
          7         2         0.20
          8         0         0.00
          9         1         0.10
          */
		 if (numericVal > 0 <= numElems)
		 {
			 //increment the iterator corresponding to the digit found
			 // iterator[((int(inputLine[0])-'0') -1)]++;   //index is computed based on the int() value of the first digit of the inputLine, minus the value of ascii(0), then subtract 1
			 iterator[((int(inputLine[0])-'0') -1)].count++;
			 iterator[((int(inputLine[0])-'0') -1)].frequency += 0.10;
		 }
      }

      // Print it - could separate this out to a function
      cout << "\nWriting data from " << fileName << ": \n\n";
	  printSampleData(counterVector);

      /*cout << "Digit     Count     Frequency \n";
      for(unsigned int i=0; i<numElems; ++i)
      {
	     //cout << "i=" << i << "..............  ";
	     //compute the frequency based on the count of each digit
	     // float frequency = counterVector[i] / numBase10Digits;
	     //float frequency = counterVector[i].count / numBase10Digits;
	     // cout << i+1 << "         " << counterVector[i] << "         " << fixed << setprecision(2) << frequency << endl;
	     //cout << i+1 << "         " << counterVector[i].count << "         " << fixed << setprecision(2) << frequency << endl;
	     cout << i+1 << "         " << counterVector[i].count << "         " << fixed << setprecision(2) << counterVector[i].frequency << endl;
      }*/
   }
   else
   {
      cout << endl << "Error: File " << fileName << " NOT opened! Check if file exists before continuing.\n\n";
      return FAILURE;
   }

   // 4. Close the file(s) and return from main()
   inFile.close();
   return SUCCESS;
}
