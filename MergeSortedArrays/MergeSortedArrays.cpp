// MergeSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> MergeSortedArrays(vector<int> vector1, vector<int> vector2);

int main()
{
    const vector<int> vector1{ 1, 4, 6, 10, 11, 15 };
    const vector<int> vector2{ 1, 5, 8, 12, 14, 19 };

    vector<int> mergedVector = MergeSortedArrays(vector1, vector2);

    cout << "[";
    for (size_t i = 0; i < mergedVector.size(); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << mergedVector[i];
    }
    cout << "]" << endl;
}

vector<int> MergeSortedArrays(vector<int> vector1, vector<int> vector2)
{
    vector<int> returnVector;
    size_t currentLeftIndex = 0;
    size_t currentRightIndex = 0;

    for (size_t currentSortedIndex = 0; currentSortedIndex < vector1.size() + vector2.size();
        ++currentSortedIndex) {

        // sortedLeft's first element comes next
        // if it's less than sortedRight's first
        // element or if sortedRight is exhausted
        if (currentLeftIndex < vector1.size()
            && (currentRightIndex >= vector2.size()
                || vector1[currentLeftIndex]< vector2[currentRightIndex])) {
            returnVector.push_back(vector1[currentLeftIndex]);
            ++currentLeftIndex;
        }
        else {
            returnVector.push_back(vector2[currentRightIndex]);
            ++currentRightIndex;
        }
    }

    return returnVector;
}
