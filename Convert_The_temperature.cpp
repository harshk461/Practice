#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        double f = celsius * 1.80 + 32.00;
        double k = celsius + 273.15;
        return {k, f};
    }
};

int main()
{

    return 0;
}