// stringReverseInPlace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void reverseString(string& stringArg);
int main()
{
    string test = "test";
    reverseString(test);
    cout << test << endl;
}

void reverseString(string& stringArg)
{
    if (stringArg.empty()) {
        return;
    }

    int leftIndex = 0;
    int rightIndex = stringArg.length() - 1;

    while (leftIndex < rightIndex) {
        // swap characters
        swap(stringArg[leftIndex], stringArg[rightIndex]);

        // move towards middle
        ++leftIndex;
        --rightIndex;
    }
}