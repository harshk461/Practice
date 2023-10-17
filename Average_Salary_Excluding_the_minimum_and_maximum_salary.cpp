#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int maxi=max_element(salary.begin(),salary.end());
        int mini=min_element(salary.begin(),salary.end());

        double total=accumulate(salary.begin(),salary.end(),0.0);
        total-=(maxi+min);

        return total/(salary.size()-2);
    }
};

int main()
{

    return 0;
}