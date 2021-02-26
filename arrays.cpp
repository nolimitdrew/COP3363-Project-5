
/* Name: Andrew Stade
Date: 3/15/2019
Section: 0004
Assignment: Homework #5 (Practice with Arrays & Functions )
Due Date: 3/15/2019
About this project: This assignment will consist of writing several functions 
that manipulate arrays or access data from arrays, as well as a test program 
that will allow interactive testing of the array functions.
Assumptions: The user will only input variables.

All work below was performed by Andrew Stade */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 40; // max array size 
const int MIN = 5; // min. array size


void menu();
void PrintArray (const int arr[], const int size);
void Shift (int arr[], int arrSIZE, int shift);
void Delete (int arr[], int arrSIZE, int index);
void Reverse (int arr[], int arrSIZE);


/*Your function prototypes here*/

int main()
{
	int arr[MAX]; //creation of array, with max size MAX.
	int arrSIZE; // the array size (changeable)
	int shift; 
	int update;
	int newValue;
	int a;
	int i;
	int index;
	double avg = 0.0;
	int temp1 = 0;
	double temp2 = 0.0;
	srand((unsigned int) time(0));
	char select = 'a';
	
	
	cout << "Welcome to the array manipulator!\n";
	cout << "How big would you like to make your array?" << endl;
	cout << "Enter a value 5 --> 40: "; // Array size declaration
	
	do 
	{
		cin >> arrSIZE;
		
		if (MAX >= arrSIZE && MIN <= arrSIZE)
		{
			cout << endl;
			menu();
			
			do
			{
				cout << "Selection > "; // the main input
				cin >> select;

				
				if (select != 'Q' && select != 'q')
				{
					switch(select)
					{
					case 'F': // randomizing values
					case 'f':
						for (a = 0; a < arrSIZE; a++)
						{
							arr[a] = rand() % 100 + 1;
						}
						cout << "Randomizing Array Data..." << endl;
						cout << endl;
						break;
					
					case 'R': // reversing array is broken :(
					case 'r':
						cout << "Reversing Array..." << endl;
						Reverse(arr,arrSIZE);
						cout << endl;
						break;
					
					case 'X': // shifts the values by 1
					case 'x':
						cout << "Shift Right by: " ;
						cin >> shift;
						Shift(arr, arrSIZE, shift);
						cout << endl;
						break;
					
					case 'C': // change values
					case 'c':
						cout << "What array index would you like to update? > " ; 
						cin >> update;
						
						if (update <= arrSIZE - 1 && update >= 0)
						{
							cout << "Change arr[" << update  << "] to what value? > " ;
							cin >> newValue;
							
							arr[update] = newValue; 
						}
						else 
						{
							cout << "Cannot insert value at arr[" << update << 
							"], arr size is: " << arrSIZE << endl;
						}
						cout << endl;
						break;
					
					case 'D': // deletion of an element
					case 'd':
						cout << "Delete element at which index? > " ;
						cin >> index;
						Delete (arr, arrSIZE, index);
						cout << "Deleting item at index " << index << endl;
						cout << endl;
						break;

					case 'A': // computes average (kinda)
					case 'a':
						for (int i = 0; i < arrSIZE; i++)
						{
							if (arr[i] > temp2)
								temp2 = arr[i];
								avg = temp2 / arrSIZE;
						}
						cout << "Average: " << avg << endl;
						cout << endl;
						break;
				
					case 'M': // displays max value
					case 'm':
						for (int i = 0; i < arrSIZE; i++)
						{
							if (arr[i] > temp1)
								temp1 = arr[i];
						}
						cout << "Max Value: " << temp1 << endl;
						cout << endl;
						break;
				
					case 'G': // can enlarge array by 5
					case 'g': 
							
							if (arrSIZE <= 35)
							{
								arrSIZE = arrSIZE + 5;
								cout << "Array size is now: " << arrSIZE << endl;
							}
							else if (arrSIZE > 35)
							{
								cout << "Cannot Grow Array. Current Size: " << 
								arrSIZE << " Maximum Size: 40" << endl;
								cout << endl;
							}
						
						break;
				
					case 'S': // can shrink array by 5
					case 's':
					
							
					
							if (arrSIZE >= 10)
							{
								arrSIZE = arrSIZE - 5;
								cout << "Array size is now: " << arrSIZE << endl;
							}
							else if (arrSIZE < 10)
							{
								cout << "Cannot Shrink Array. Current Size: " << 
								arrSIZE << " Minimum Size: 5" << endl;
								cout << endl;
							}
							
						break;
				
					case 'P': // good
					case 'p':
						PrintArray(arr, arrSIZE);
						break;
				
					default:
						cout << "Invalid Selection." << endl;
						cout << endl;
					}
				}
			} while (select != 'Q' && select != 'q');
		}
		
		else if (MAX <= arrSIZE || MIN >= arrSIZE) // error check if else
		{
			cout << "Try Again: " ;
		}

		
	} while (select != 'Q' && select != 'q');
	
	//Enter a loop that presents the user with the menu and manipulates array based on menu choice.
	cout << "Goodbye!" << endl;
	cout << endl;
	
	
	return 0;
}
	


//GIVEN: PrintArray Function
//This function prints the contents of any interger array of any size seperated by commas

void menu() // main menu (in a function to make int main() more clean) 
{
	cout << "MENU: (or SELECT Q TO QUIT)" << endl;
	cout << "F - Fill Array: RANDOM values 1 - 100" << endl;
	cout << "R - Reverse Array Contents" << endl;
	cout << "X - Shift Right" << endl;
	cout << "C - Change Array Element" << endl;
	cout << "D - Delete Array Element" << endl;
	cout << "A - Print Average" << endl;
	cout << "M - Print Max Value" << endl;
	cout << "G - Grow Array Size by 5" << endl;
	cout << "S - Shrink Array Size by 5"<< endl;
	cout << "P - Print Array" << endl;
	cout << "---------------------------" << endl;
}

void PrintArray(const int arr[], const int size) // the print array function
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < size-1; i++)	// for loop, prints each item
		cout << arr[i] << ", ";

	cout << arr[size-1] << " }\n\n";	// prints last item , no comma
}

void Shift (int arr[], int arrSIZE, int shift) // shifts all values to the right
{
        int temp1 = 0;

        do
        {
                temp1 = arr[arrSIZE-1];

                for (int i = arrSIZE; i >= 1 ; i --)
                {
                        arr[i] = arr[i-1];
                }           

                arr[0] = temp1;
                shift--;
				
        } while(shift > 0);

}


void Delete (int arr[], int arrSIZE, int index) // void delete function
{
	for (int index = 0; index < arrSIZE; index++)
		arr[index] = arr[index + 1];
		arr[arrSIZE-1];
}

void Reverse (int arr[], int arrSIZE) // broken reverse function :(
{	
	int i;
	
	for (int i = arrSIZE-1; i >= 0; i--)
		arr[i] = arr[arrSIZE-i-1];
		arr[arrSIZE-i-1] = arr[i];
}


