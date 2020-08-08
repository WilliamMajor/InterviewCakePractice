// onDemandMovieStreaming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


bool CanWatchTwoMovies1(int flightLength, vector<int> movieLengths);
bool CanWatchTwoMovies(int flightLength, vector<int> movieLengths);

int main()
{
    int flightLength = 240;
    vector<int> movieLengths = { 90, 120, 130, 140, 80, 70, 200, 100, 110 };// this should have a true return;
    vector<int> movieLenghts1 = { 90, 120, 130, 140, 80, 70, 200 }; // this should have a false return;

    bool result1 = CanWatchTwoMovies(flightLength, movieLengths);
    bool result2 = CanWatchTwoMovies(flightLength, movieLenghts1);
    bool result3 = CanWatchTwoMovies1(flightLength, movieLengths);
    bool result4 = CanWatchTwoMovies1(flightLength, movieLenghts1);

    cout << "yeet" << endl;

}

//Find if two movies will be exactly the length of the flight.
bool CanWatchTwoMovies(int flightLength, vector<int> movieLengths) //solution O(2N)
{
    for (int movieIndex = 0; movieIndex < movieLengths.size(); movieIndex++)
    {
        for (int movieIndexInternal = 0; movieIndexInternal < movieLengths.size(); movieIndexInternal++)
        {
            if (movieIndex != movieIndexInternal)
            {
                if (movieLengths[movieIndex] + movieLengths[movieIndexInternal] == flightLength)
                    return true;
            }
        }
    }
    return false;
}

bool CanWatchTwoMovies1(int flightLength, vector<int> movieLengths)
{
    unordered_set<int> moviesSeen;

    for (int firstMovieLength : movieLengths)
    {
        int secondMovieLength = flightLength - firstMovieLength;
        if (moviesSeen.find(secondMovieLength) != moviesSeen.end())
        {
            return true;
        }
        moviesSeen.insert(firstMovieLength);
    }
    return  false;
}
