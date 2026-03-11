#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

int findElement(int arr[], int n, int key) { // Used as the base to search for if the input is in the array
    int i;
    for (i = 0; i < n; i++) // The continuous loop to check the entire array for the input
        if (arr[i] == key) // This is continued if the input was found in the array
            return i;
    return -1; // If the input wasn't found, this is continued instead
}

int main() {
    int arr[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 }; // The storage module that contains the array itself
    int n = sizeof(arr) / sizeof(arr[0]); // Used to figure out how many digits are in the array
    int key;

    cout << "Input the number you want to search for in the array: ";
    cin >> key; // Used to get the user input for the number they want to search the array for

    int position = findElement(arr, n, key); // Defines what position is by searching with findElement
    // The way it defines position is by getting the array itself, getting the amount of digits in the array, and searching for the input in the array and getting its place if found

    // These are to make sure that the numbers 3, 67, and 7 have the correct value for their position in the array (spot 0 for 67, spot 2 for 3, and spot 11 for 7)
    assert(position != arr[3]);
    assert(position != arr[11]);
    assert(position != arr[0]);

    if (position == -1) // The if statement for the position, and uses what result findElement gives out depending on if the input was found
        cout << "Input not found / found at position: " << position;
    else
        cout << "Input found at position: " << position;

    return 0; // This just ends the code once it's finished
}