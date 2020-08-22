// highestSumOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int highestSumOfThree(vector<int> inputVector);

int main()
{
    vector<int> inputVector{ 4, 6, 7, 3, 10, 32, 18, 9 };

    cout << highestSumOfThree(inputVector) << endl;
}

int highestSumOfThree(vector<int> inputVector)
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