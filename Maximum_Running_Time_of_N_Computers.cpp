#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        sort(batteries.begin(), batteries.end());

        // Max battery is greater than the average, so it can last forever
        // Reduce the problem from size n to size n - 1
        while (batteries.back() > sum / n)
        {
            sum -= batteries.back();
            batteries.pop_back();
            n--;
        }

        // If the max battery <= average running time,
        // It won't be waste, and so do smaller batteries
        return sum / n;
    }
    bool isPossible(int n, vector<int> &arr, long long time)
    {
        long long conti = 0;
        for (auto b : arr)
            conti += min(b, time);
        return conti >= n * time;
    }

    long long maxRunTime(int n, vector<int> &batteries)
    {
        long batSum = 0;
        for(int battery:batteries) batSum += battery;
        long start = 0;
        long end = batSum/n+1;
        
        while(start<end){
            long mid = start+(end-start)/2;
            if(canFit(n, batteries, mid)){
                start = mid+1;
            }
            else end = mid;
        }
        return start-1;
    }
};

int main()
{

    return 0;
}