#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;
void sort(int myArray[], int size);

int main() {
	int myArray[]{ 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 }; // This has all the numbers in the array, and can be in whatever order
	int size = sizeof(myArray) / sizeof(myArray[0]); // This divides the array of numbers to figure out how many different digits there are

	sort(myArray, size); // This is used to have sort defined more simply than at the top

	for (int element : myArray) { // This is the loop that constantly gives the output for the next number
		std::cout << element << " "; // This is how the output is formatted, with a space right after it to make each digit easier to read
	}

	return 0;
}

void sort(int myArray[], int size) { // This is what sort uses to actually sort all the numbers in the array

	int storage; // Temporary storage to briefly store a number when moving it
	for (int i = 0; i < size - 1; i++) { // Used as the base for defining how many digits are in the array
		for (int j = 0; j < size - i - 1; j++) { // Used to constantly loop the way it checks if the current number is smaller or bigger than the next
			// You can change the arrow's direction in if statement below between < (sort in descending order) or > (sort in ascending order) to make the numbers be sorted in that way
			if (myArray[j] < myArray[j + 1]) { // Used to actually check if the current number is smaller or larger than the next number.
				storage = myArray[j]; // Used as temporary storage for when the current number is smaller or larger than the next number
				myArray[j] = myArray[j + 1]; // Used to increase the place in the array that the number is
				myArray[j + 1] = storage; // Used to increase the number's place in the storage so it knows what place the number is once it finds a number that is smaller than it
			}
		}
	}
}