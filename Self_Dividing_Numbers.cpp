#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int n)
    {
        vector<int> arr;
        int temp = n;
        while (temp > 0)
        {
            int rem = temp % 10;
            if (rem == 0)
                return false;
            arr.push_back(rem);
            temp /= 10;
        }

        for (auto it : arr)
            if (n % it != 0)
                return false;
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (check(i))
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{

    return 0;
}