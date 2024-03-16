#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int encrypt(int n)
    {
        int l = 0;
        int maxi = 0;
        while (n > 0)
        {
            int r = n % 10;
            maxi = max(r, maxi);
            l++;
            n /= 10;
        }

        string s = "";
        for (int i = 0; i < l; i++)
            s += to_string(maxi);

        return stoi(s);
    }

public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = encrypt(nums[i]);

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{

    return 0;
}