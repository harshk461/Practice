#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int firstDigit(int num)
    {
        return to_string(num)[0] - '0';
    }
    int lastDigit(int num)
    {
        return num % 10;
        ;
    }

public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (__gcd(firstDigit(nums[i], lastDigit(nums[j]))) == 1)
                    count++;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}