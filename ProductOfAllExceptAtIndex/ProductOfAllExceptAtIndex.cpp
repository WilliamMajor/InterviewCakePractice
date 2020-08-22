// ProductOfAllExceptAtIndex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(vector<int> inputs);
vector<int> getProductsOfAllIntsExceptAtIndex1(vector<int> inputs);

int main()
{
    vector<int> inputs{ 1, 7, 3, 4 };

    vector<int> result = getProductsOfAllIntsExceptAtIndex(inputs);
    
}

vector<int> getProductsOfAllIntsExceptAtIndex(vector<int> inputs) //O(n^2) solution O(n) size
{
    vector<int> output(inputs.size(), 1);
    for (int idx = 0; idx < inputs.size(); idx++)
    {
        for (int jdx = 0; jdx < inputs.size(); jdx++)
        {
            if (jdx != idx)
            {
                output[idx] *= inputs[jdx];
            }
        }
    }
    return output;
}

vector<int> getProductsOfAllIntsExceptAtIndex1(vector<int> inputs) //O(n) solution O(n) size
{
    if (inputs.size() < 2) {
        throw invalid_argument("Getting the product of numbers at"
            " other indices requires at least 2 numbers");
    }


    vector<int> productsOfAllIntsExceptAtIndex(inputs.size());

    int productSoFar = 1;
    for (size_t i = 0; i < inputs.size(); ++i) {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= inputs[i];
    }

    productSoFar = 1;
    for (size_t i = inputs.size(); i > 0; --i) {
        size_t j = i - 1;
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= inputs[j];
    }

    return productsOfAllIntsExceptAtIndex;
}