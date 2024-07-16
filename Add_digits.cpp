#include <bits/stdc++.h>
using namespace std;

int addDigits(int num)
{
    return 1 + (num - 1) % 9;
}

int main()
{
    addDigits(38);
    return 0;
}