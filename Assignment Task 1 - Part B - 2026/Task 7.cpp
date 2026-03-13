#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    // Below is the vector that is used to set pair to have two integers and then define pairs with the numbers contained in the curly brackets
    vector<pair<int, int>> pairs = { {67, 13}, {3, 89}, {43, 2}, {19, 71}, {5, 61}, {97, 7}, {37, 31}, {17, 11}, {83, 53}, {23, 29} };

    // This is what actually sorts the pairs of integers, and sorts them in ascending order by default
    sort(pairs.begin(), pairs.end());

    // This is the loop that is used to print each of the pairs once they're sorted
    for (const auto& p : pairs) { // What const auto& does is constantly and automatically convert auto into an int (since that's what's needed) and shortens pairs down to p
        cout << "(" << p.first << ", " << p.second << ") "; // Each of the pairs printed are contained in brackets to make it easier to tell which numbers are paired together
    }

    return 0;
}