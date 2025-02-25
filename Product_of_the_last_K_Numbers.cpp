#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class ProductOfNumbers
{
public:
    vector<int> arr;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        arr.push_back(num);
    }

    int getProduct(int k)
    {
        int n = arr.size();
        long long ans = 1;
        for (int i = n - 1; i > n - k - 1; i--)
            ans *= arr[i];
        return ans;
    }
};

class ProductOfNumbers
{
public:
    vector<int> prefix;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (prefix.empty())
        {
            prefix.push_back(num);
        }
        else
        {
            int pre = prefix.back();
            prefix.push_back(pre * num);
        }
    }

    int getProduct(int k)
    {
        int n = prefix.size();
        return prefix[n - 1] - prefix[n - k - 1];
    }
};

int main()
{

    return 0;
}