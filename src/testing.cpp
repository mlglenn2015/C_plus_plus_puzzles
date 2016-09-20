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

int main()
{
  string fileName;
  //FILE *inputFile;
  string inputLine;

  const float numBase10Digits = 10.0;
  //Vector containing 9 elements
  const size_t numElems = 9;

  vector<int> counterVector(numElems);
  //vector<int>::iterator iterator = counterVector.begin();
  //vector<float> frequencyVector(numElems);
  //int counterArray[numElems];

  //initialize the vector
  for(int i = 0; i < numElems; i++){
     counterVector.push_back(i);
	 //frequencyVector.push_back(i);
  }
  vector<int>::iterator iterator = counterVector.begin();

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

     cout << "File " << fileName << " successfully opened, reading ... \n";

  /*if (FILE *inputFile = fopen(fileName.c_str(), "r")) {
        cout << "File " << fileName << " successfully opened, reading ... " << endl;
      fclose(inputFile);
      return true; */

      /*
 	   2. Read input file, ignoring white space, comments and any line that starts with char 0. Load each line of data into the vector.
	   */

      while (getline(inFile, inputLine))
      {
         cout << "\ninputLine: " << inputLine << endl;

		 int numericVal;
		 istringstream iss(inputLine);
		 iss >> numericVal;

		 cout << "numericVal: " << numericVal << endl;

		 if (numericVal > 0)
		 {
		     //Get the count for the first digit
		     cout << "********* Inspecting: " << numericVal << endl;
             cout << "********* First digit:" << inputLine[0] << endl;  //We stored inputLine as a string so we can reference the first character here and assign to our array
			 //cout << "********* First digit:" << inputLine.at(0) << endl; //inputLine[0] returns a char&

			 //string tmpStr = inputLine[0];
			 char tmpChar = inputLine[0];
			 cout << "tmpChar: " << tmpChar << endl;

			 //int tmp;
			 //stringstream("1") >> tmp;

			 //std::string s = to_string(inputLine[0]);
			 //cout << s << endl;

             //int tmpInt = atoi((char*)&inputLine[0]); //assigns array element 0
			 //int tmpInt = (int)tmpChar;                 //assigns ascii value of the character

			 //int tmpInt = int(tmpChar)-'0';
			 int tmpInt = int(inputLine[0])-'0';
             cout << "tmpInt: " << tmpInt << endl;

			 int arrayIdx = tmpInt -1;
             cout << "arrayIdx: " << arrayIdx << endl;


			 //int arrVal = counterArray[arrayIdx]++;   not what we want
			 /*int *arrVal = &counterArray[arrayIdx];
			 cout << "arrVal: " << *arrVal << endl;
			 *(arrVal)++;
			 cout << "arrVal: " << *arrVal << endl;*/

			 //counterVector.push_back(arrayIdx);

			 //*iterator++;

			 //increment the iterator corresponding to the digit found
			 iterator[arrayIdx]++;

			 cout << "counterVector[arrayIdx] where arrayIdx = " << arrayIdx << " : " << counterVector[arrayIdx] << endl;

			 cout << "counterVector[0]: " << counterVector[0] << "  iterator[0] :" << iterator[0] << endl;
			 cout << "counterVector[1]: " << counterVector[1] << "  iterator[1] :" << iterator[1] << endl;
			 cout << "counterVector[2]: " << counterVector[2] << "  iterator[2] :" << iterator[2] << endl;
			 cout << "counterVector[3]: " << counterVector[3] << "  iterator[3] :" << iterator[3] << endl;
			 cout << "counterVector[4]: " << counterVector[4] << "  iterator[4] :" << iterator[4] << endl;
			 cout << "counterVector[5]: " << counterVector[5] << "  iterator[5] :" << iterator[5] << endl;
			 cout << "counterVector[6]: " << counterVector[6] << "  iterator[6] :" << iterator[6] << endl;
			 cout << "counterVector[7]: " << counterVector[7] << "  iterator[7] :" << iterator[7] << endl;
			 cout << "counterVector[8]: " << counterVector[8] << "  iterator[8] :" << iterator[8] << endl;

			 //vec.push_back(i);



             //counterArray[arrayIdx] = counterArray[arrayIdx]+1;
			 //counterArray[tmpInt-1] = counterArray[tmpInt-1] + 1;


		 }

      }

      /*
       3. Iterate through the vector and write the output to the console, counting the occurrences of the first number in each entry.

       What we know:
          1. The assignment expects counts for integers 1 through 9. Some integers will have 0 for the count. We will count the occurrences of numbers 1 through 9.
          2. The output appears to be formatted into fixed-width columns
          3. The Frequency is a floating point decimal that can be computed as ratio of the total number of base-10 digits (0-9).

       Example Output:
       Digit     Count     Frequency
       --------  --------  -----------
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

      cout << "\nWriting data from " << fileName << ": \n\n";
      cout << "Digit     Count     Frequency \n";
      //cout << "--------  --------  -----------\n";
      // Display the vector elements
      for(unsigned int i=0; i<numElems; ++i)
      {
		 //compute the frequency based on the count of each digit
		 //float frequency = 0.00;
		 //float frequency = 3 / 10.0;
		 float frequency = counterVector[i] / numBase10Digits;
		 //cout.precision(4);
		 //cout << i+1 << "         " << counterVector[i] << "         " << setprecision(2) << frequency << endl;
		 cout << i+1 << "         " << counterVector[i] << "         " << fixed << setprecision(2) << frequency << endl;
      }


  }
  else
  {
      cout << endl << "Error: File " << fileName << " NOT opened! Check if file exists before continuing.\n\n";
      return FAILURE; //error on opening file
  }

  // 4. Close the file(s) and return from main()
  //fclose(inputFile);
  inFile.close();
  return SUCCESS; //success
}
