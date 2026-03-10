#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;


int findElement(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

int main() {
    int arr[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Input the number you want to search for in the array: ";
    cin >> key;

    int position = findElement(arr, n, key);

    assert(position != arr[3]);
    assert(position != arr[11]);
    assert(position != arr[0]);

    if (position == -1)
        cout << "Input not found / found at position: " << position;
    else
        cout << "Input found at position: " << position;

    return 0;
}