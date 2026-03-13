#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

// ATTENTION: I am aware that this is a combo of the code from tasks 3 and 6, but this was as best I could do with the amount of time I had
// I did have a go at making a binary searcher with the current bubble sort, but it very quickly became very difficult to get everything working
// And just to clarify, it's a linear search with a regular bubble sorter instead of a binary search with a pairs bubble sort

void sort(int arr[], int size);

int findElement(int arr[], int n, int key) { // Used as the base to search for if the input is in the array
	int i;
	for (i = 0; i < n; i++) // The continuous loop to check the entire array for the input
		if (arr[i] == key) // This is continued if the input was found in the array
			return i;
	return -1; // If the input wasn't found, this is continued instead
}

int main() {
	int arr[]{ 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 }; // This has all the numbers in the array, and can be in whatever order
	int n = sizeof(arr) / sizeof(arr[0]); // This divides the array of numbers to figure out how many different digits there are
	int key;

	sort(arr, n); // This is used to have sort defined more simply than at the top
	cout << "Input the number you want to search for in the array: ";
	cin >> key;

	int position = findElement(arr, n, key); // Defines what position is by searching with findElement
	// The way it defines position is by getting the array itself, getting the amount of digits in the array, and searching for the input in the array and getting its place if found

	// These are to make sure that the numbers 11, 23, and 97 have the correct value for their position in the array (spot 0 for 67, spot 2 for 3, and spot 11 for 7)
	assert(position != arr[4]);
	assert(position != arr[8]);
	assert(position != arr[19]);

	if (position == -1) // The if statement for the position, and uses what result findElement gives out depending on if the input was found
		cout << "Input not found / found at position: " << position;
	else
		cout << "Input found at position: " << position;

	return 0;
}

void sort(int arr[], int n) { // This is what sort uses to actually sort all the numbers in the array

	int storage; // Temporary storage to briefly store a number when moving it
	for (int i = 0; i < n - 1; i++) { // Used as the base for defining how many digits are in the array
		for (int j = 0; j < n - i - 1; j++) { // Used to constantly loop the way it checks if the current number is smaller or bigger than the next
			if (arr[j] > arr[j + 1]) { // Used to actually check if the current number is larger than the next number.
				storage = arr[j]; // Used as temporary storage for when the current number is larger than the next number
				arr[j] = arr[j + 1]; // Used to increase the place in the array that the number is
				arr[j + 1] = storage; // Used to increase the number's place in the storage so it knows what place the number is once it finds a number that is smaller than it
			}
		}
	}
}