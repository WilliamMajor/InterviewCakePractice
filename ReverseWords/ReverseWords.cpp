// ReverseWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

string ReverseWords(string input);

int main()
{
    string test = "this is a test";

    cout << ReverseWords(test) << endl;


}

string ReverseWords(string input)
{
    string output = "";
    vector<string> temp;

    size_t pos = 0;
    string delimeter = " ";

    do
    {
        pos = input.find(delimeter);
        temp.push_back(input.substr(0, pos));
        input.erase(0, pos + delimeter.length());
    } while (pos != string::npos);
    
    while (!temp.empty())
    {
        output += temp.back() + " ";
        temp.pop_back();
    }

    return output;
}