// highestSumOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int highestSumOfThree(vector<int> inputVector);
int highestProductOfThree(vector<int> inputVector);

int main()
{
    vector<int> inputVector{ 4, 6, 7, 3, 10, 32, 18, 9 };
    vector<int> vectorOfInts({ 1, 10, -5, 1, -100 });

    cout << highestSumOfThree(inputVector) << endl;
    cout << highestProductOfThree(inputVector) << endl;
    cout << highestProductOfThree(vectorOfInts) << endl;
}

int highestSumOfThree(vector<int> inputVector) // O(n) time and O(n) space
{
    int returnValue = 0;
    priority_queue<int> pq;
    for (int idx = 0; idx < inputVector.size(); idx++)
    {
        pq.push(inputVector[idx]);
    }

    for (int idx = 0; idx < 3; idx++)
    {
        returnValue += pq.top();
        pq.pop();
    }
    return returnValue;
}

int highestProductOfThree(vector<int> inputVector) //O(n) time and O(1) space
{
    int highest = 0;
    int lowest = 0;
    int highestProductof3 = 0;
    int highestProductof2 = 0;
    int lowestProductOf2 = 0;
    if (inputVector.size() < 3)
    {
        return 0;
    }

    //sort(inputVector.begin(), inputVector.end());
    //reverse(inputVector.begin(), inputVector.end());

    highest = inputVector[0];
    lowest = inputVector[0];

    for (int idx = 1; idx < inputVector.size(); idx++)
    {
        if (inputVector[idx] > highest)
        {
            highestProductof2 = highest * inputVector[idx];
            highest = inputVector[idx];
        }
        else if ((inputVector[idx] * highest) > highestProductof2)
        {
            highestProductof3 = highestProductof2 * inputVector[idx];
            highestProductof2 = highest * inputVector[idx];
        }
        else if ((inputVector[idx] * highestProductof2) > highestProductof3 || (inputVector[idx] * lowestProductOf2) > highestProductof3)
        {
            highestProductof3 = max((inputVector[idx] * highestProductof2), (inputVector[idx] *  lowestProductOf2));
        }

        if (inputVector[idx] < lowest)
        {
            lowestProductOf2 = lowest * inputVector[idx];
            lowest = inputVector[idx];
        }
        else if ((inputVector[idx] * lowest) < lowestProductOf2)
        {
            lowestProductOf2 = lowest * inputVector[idx];
        }
    }
    return highestProductof3;

}