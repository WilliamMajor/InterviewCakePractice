// PermutationPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

bool permutationPalindrome(string inputString);

int main()
{
    string test1 = "civic";
    string test2 = "ivicc";
    string test3 = "civil";

    bool result1 = permutationPalindrome(test1);
    bool result2 = permutationPalindrome(test2);
    bool result3 = permutationPalindrome(test3);
}


bool permutationPalindrome(string inputString)
{
    unordered_set<char> unpairedCharacters;

    for (char c : inputString)
    {
        if (unpairedCharacters.find(c) != unpairedCharacters.end())
        {
            unpairedCharacters.erase(c);
        }
        else
        {
            unpairedCharacters.insert(c);
        }
    }
    return unpairedCharacters.size() <= 1;
}