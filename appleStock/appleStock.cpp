// appleStock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int getMaxProfit(vector<int> stockPrices);
int getMaxProfit2(vector<int> stockPrices);

int main()
{
    vector<int> stockPrices{ 10, 7, 5, 8, 11, 9 };
    vector<int> stockPrices2{ 10, 7, 5, 8, 6, 9 };
    vector<int> stockPrices3{ 10, 7, 5, 3, 2, 1 };

    cout << getMaxProfit2(stockPrices) << endl;
    cout << getMaxProfit2(stockPrices2) << endl;
    cout << getMaxProfit2(stockPrices3) << endl;

}

int getMaxProfit(vector<int> stockPrices) // simple but O(n^2) time with O(1) size
{
    int maxDiff = INT32_MIN;
    if (stockPrices.empty())
    {
        return 0;
    }

    for (int idx = 0; idx < stockPrices.size() - 1; idx++)
    {
        for (int jdx = idx + 1; jdx < stockPrices.size(); jdx++)
        {
            if ((stockPrices[jdx] - stockPrices[idx]) > maxDiff)
            {
                maxDiff = (stockPrices[jdx] - stockPrices[idx]);
            }
        }
    }
    return maxDiff;

}

int getMaxProfit2(vector<int> stockPrices) // O(n) time and O(1) space solution
{
    int maxProfit = INT32_MIN;
    int minPrice = INT32_MAX;
    if (stockPrices.empty())
    {
        return 0;
    }

    for (int idx = 0; idx < stockPrices.size(); idx++)
    {
        if (stockPrices[idx] < minPrice)
        {
            minPrice = stockPrices[idx];
            if (idx >= 1)
            {
                if (minPrice - stockPrices[idx - 1] > maxProfit)
                    maxProfit = minPrice - stockPrices[idx - 1];
            }
            
        }
        else if (stockPrices[idx] - minPrice > maxProfit)
        {
            maxProfit = stockPrices[idx] - minPrice;
        }

    }
    return maxProfit;
}
