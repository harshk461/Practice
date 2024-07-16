#include <iostream>
using namespace std;

class Solution
{
private:
    bool isInside(int day, vector<int> &arr)
    {
        // if day is outside the range
        if (day < arr[0] || day > arr[1])
            return false;
        return true;
    }
    int brute(int days, vector<vector<int>> &meetings)
    {
        int count = 0;
        sort(meetings.begin(), meetings.end());
        for (auto it : meetings)
            if (isInside())
    }

public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        return brute(days, meetings);
    }
};

int main()
{

    return 0;
}