#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    // contains max number among small elements
    priority_queue<int> maxi;
    // contains lowest number among higher elements
    priority_queue<int, vector<int>, greater<int>> mini;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();

        if (maxi.size() < mini.size())
        {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian()
    {
        if (maxi.size() == mini.size())
        {
            double n1 = (double)maxi.top();
            double n2 = (double)mini.top();

            return (n1 + n2) / 2;
        }

        return (double)maxi.top();
    }
};

int main()
{

    return 0;
}