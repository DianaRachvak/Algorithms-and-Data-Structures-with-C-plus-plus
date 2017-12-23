/*
Diana Rachvak
Description: *Quick Sort Template*
             This is a C++ program that has a template version of the
             QuickSort algorithm that works with any data type.
             All output goes to the file QSToutput.txt.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

/*
*Template function T partition()
*Input:
*    array- an array of any data type
*    start- integer, represinting start position in array
*    end- integer, represents end position in array
*Process:
*    uses the QuickSort algorithm to sort an array from array[start]
*    to array[end]
*Output:
*    returns pivot point
*/
template <class T>
T partition(T array[], int start, int end)
{
    T pivotValue = array[start];
    int pivotPosition = start;

    for (int pos = start + 1; pos <= end; pos++)
    {
        if (array[pos] < pivotValue)
        {
            //swaps current item with the item to the right
            swap(array[pivotPosition + 1], array[pos]);
            //swaps current item with a pivot point
            swap(array[pivotPosition], array[pivotPosition + 1]);
            pivotPosition ++;
        }
	}
    return pivotPosition;
}

/*
*Template function void quickSort()
*Input:
*    array- an array of any data type
*    start- integer, represinting start position in array
*    end- integer, represents end position in array
*Process:
*    sorts an array so that all the values that are greater or equal
*    to the pivot point are to the right, and all valuues than the
*    pivot point are to the left
*Output:
*    returns sorted array
*/
template <class T>
void quickSort(T array[], int start, int end)
{
    if (start < end)
    {
        int p = partition(array, start, end); //gets pivot point
        quickSort(array, start, p - 1); //sorts before pivot point
        quickSort(array, p + 1, end); //sorts after pivot point
	}
}

//start of the main
int main()
{
    ofstream toFile("QSToutput.txt");

    toFile<<endl<<"******Diana Rachvak******"<<endl<<endl;

    const int MAX = 11, MAX2 = 8, MAX3 = 16;

    int intArray[MAX] = {9,12,4,78,34,55,90,123,45,23,12};

    double doubleArray[MAX] = {3.56, 6.04, 5.78, 78.01, 78.00, 23.09,
                               14.99, 43.56, 67.89, 78.90, 12.34};

    float floatArray[MAX2] = {476644, 78.09576, 0.364533, 58565.966,
                              56.7680, 789.0563, 1.23456, 0.89721135};

    char charArray[MAX3] = "computerScience";

    //demonstrating work of template functions with array of ints,
    // doubles, floats and chars

    /*********************Array of integers********************/

    toFile<<"The array of integers: ";

    for(int n=0; n<MAX; n++) //prints intArray
    {
       toFile << intArray[n] << " ";
    }  toFile << endl;

    quickSort(intArray, 0, MAX-1); // Sorts the intArray

    toFile<<"Sorted array of integers: ";

    for(int n=0; n<MAX; n++) //prints sorted intArray
    {
       toFile << intArray[n] << " ";
    }  toFile << endl<<endl;

    /*********************Array of doubles**********************/

    toFile<<"The array of doubles: ";

    for(int n=0; n<MAX; n++) //prints doubleArray
    {
       toFile << doubleArray[n] << " ";
    }  toFile << endl;

    quickSort(doubleArray, 0, MAX-1); // Sorts doubleArray

    toFile<<"Sorted array of doubles: ";

    for(int n=0; n<MAX; n++) //prints sorted doubleArray
    {
       toFile << doubleArray[n] << " ";
    }  toFile << endl<<endl;


    /*****************Array of floats************************/

    toFile<<"The array of floats: ";

    for(int n=0; n<MAX2; n++) //prints floatArray
    {
       toFile << floatArray[n] << " ";
    }  toFile << endl;

    quickSort(floatArray, 0, MAX2-1); // Sorts floatArray

    toFile<<"Sorted array of floats: ";

    for(int n=0; n<MAX2; n++) //prints sorted floatArray
    {
       toFile << floatArray[n] << " ";
    }  toFile << endl<<endl;

    /*****************Array of chars************************/

    toFile<<"The array of chars: ";

    for(int n=0; n<MAX3; n++) //prints charArray
    {
       toFile << charArray[n];
    }  toFile << endl;

    quickSort(charArray, 0, MAX3-1); // Sorts charArray

    toFile<<"Sorted array of chars: ";

    for(int n=0; n<MAX3; n++) //prints sorted charArray
    {
       toFile << charArray[n] << " ";
    }  toFile << endl<<endl;

    toFile.close();
    return 0;
} //end main
