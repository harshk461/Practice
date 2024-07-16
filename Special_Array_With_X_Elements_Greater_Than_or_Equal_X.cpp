#include <iostream>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            int temp = 0;
            for (auto it : nums)
                if (it >= i)
                    temp++;

            if (i == temp)
                return i;
        }
        return -1;
    }
};

int main()
{

    return 0;
}