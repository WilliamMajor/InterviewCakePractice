// wordCloud.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> BuildWordCloud(string inputString);

int main()
{
    unordered_map<string, int> test = BuildWordCloud("After beating the eggs, Dana read the next step: Add milk and eggs, then add flour and sugar.");

}

unordered_map<string,int> BuildWordCloud(string inputString)
{
    unordered_map<string, int> wordCount;
    string lowerCase = "";
    string token;
    size_t pos = 0;

    for (size_t idx = 0; idx < inputString.length(); idx++)
    {
        lowerCase += tolower(inputString[idx]);
    }

    while ((pos = lowerCase.find(" ")) != std::string::npos) 
    {
        token = lowerCase.substr(0, pos);
        for (int i = 0, len = token.size(); i < len; i++)
        {
            // check whether parsing character is punctuation or not 
            if (ispunct(token[i]))
            {
                token.erase(i--, 1);
                len = token.size();
            }
        }
        if (wordCount.find(token) == wordCount.end())
        {
            wordCount.insert(pair<string, int>(token, 1));
        }
        else
        {
            wordCount[token]++;
        }
        lowerCase.erase(0, pos + 1);
    }
    return wordCount;
}