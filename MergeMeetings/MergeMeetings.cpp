// MergeMeetings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }


};

vector<Meeting> MergeRanges(vector<Meeting> meetingsArg);
void SortMeetings(vector<Meeting>& vectorToSort);

int main()
{
    vector<Meeting> testcase = { Meeting(1, 10), Meeting(2, 6), Meeting(3, 5), Meeting(7, 9) };

    vector<Meeting> result = MergeRanges(testcase);
}



// O(n log n) solution
vector<Meeting> MergeRanges(vector<Meeting> meetingsArg)
{
    //First sort the meetings using merge sort
    SortMeetings(meetingsArg);

    for (int idx = 0; idx < meetingsArg.size() - 1; idx++)
    {
        if (meetingsArg[idx].getEndTime() >= meetingsArg[idx + 1].getStartTime())
        {
            if (meetingsArg[idx].getEndTime() < meetingsArg[idx + 1].getEndTime())
            {
                meetingsArg[idx].setEndTime(meetingsArg[idx + 1].getEndTime());
            }
            meetingsArg.erase(meetingsArg.begin() + idx + 1);
            idx = -1;
        }
    }


    return meetingsArg;
}

void SortMeetings(vector<Meeting>& vectorToSort)
{
    // BASE CASE: arrays with fewer than 2 elements are sorted
    if (vectorToSort.size() < 2) {
        return;
    }

    // STEP 1: divide the array in half
    // we use integer division, so we'll never get a "half index"
    size_t midIndex = vectorToSort.size() / 2;

    vector<Meeting> left(vectorToSort.begin(), vectorToSort.begin() + midIndex);
    vector<Meeting> right(vectorToSort.begin() + midIndex, vectorToSort.end());

    // STEP 2: sort each half
    SortMeetings(left);
    SortMeetings(right);

    // STEP 3: merge the sorted halves
    size_t currentLeftIndex = 0;
    size_t currentRightIndex = 0;

    for (size_t currentSortedIndex = 0; currentSortedIndex < vectorToSort.size();
        ++currentSortedIndex) {

        // sortedLeft's first element comes next
        // if it's less than sortedRight's first
        // element or if sortedRight is exhausted
        if (currentLeftIndex < left.size()
            && (currentRightIndex >= right.size()
                || left[currentLeftIndex].getStartTime() < right[currentRightIndex].getStartTime())) {
            vectorToSort[currentSortedIndex] = left[currentLeftIndex];
            ++currentLeftIndex;
        }
        else {
            vectorToSort[currentSortedIndex] = right[currentRightIndex];
            ++currentRightIndex;
        }
    }
}