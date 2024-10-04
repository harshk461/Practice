#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionAddition(string expression)
    {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();

        while (i < n)
        {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-')
            {
                if (expression[i] == '-')
                    sign = -1;
                i++;
            }

            int num = 0;
            // numerator
            while (i < n && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            // '/' character
            i++;

            // denomenator starts
            int den = 0;
            while (i < n && isdigit(expression[i]))
            {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerator = numerator * den + num * denominator;
            denominator *= den;

            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};

int main()
{

    return 0;
}