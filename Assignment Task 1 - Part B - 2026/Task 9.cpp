#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

int main() {
	int first = 20;
	int second = 10;
	int temp = first; // This is used as temp storage to store the value from first
	int* firstptr = &first; // This points at the address from &first (which is 0000000F310FF6B4) and stores the memory
	int* secondptr = &second; // This does the same as firstptr, but does it for second (the address for second is 000000C08C3FFC44)

	*firstptr = *secondptr; // This dereferences the seeds for both firstptr and secondptr and then sets first as the dereferenced secondptr
	second = temp; // This sets the value from temp as the value of second, but doesn't need to be dereferenced

	// These then print out the new values of first and second now that they've been swapped
	cout << first << endl;
	cout << second << endl;
	return 0;
}