#include <bits/stdc++.h>
using namespace std;

class Bank
{
public:
    vector<long long> arr;
    int n;
    Bank(vector<long long> &balance)
    {
        this->arr = balance;
        this->n = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n || arr[account1 - 1] < money)
            return false;

        arr[account1 - 1] -= money;
        arr[account2 - 1] += money;

        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account < 1 || account > n)
            return false;
        arr[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > n || arr[account - 1] < money)
            return false;
        arr[account - 1] -= money;
        return true;
    }
};

int main()
{

    return 0;
}