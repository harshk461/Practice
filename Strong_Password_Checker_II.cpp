#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkSpecial(char ch)
    {
        string s = "!@#$%^&*()-+";
        for (auto it : s)
            if (it == ch)
                return true;
        return false;
    }

public:
    bool strongPasswordCheckerII(string password)
    {
        if (password.length() < 8)
            return false;

        unordered_map<string, bool> flags;
        flags["lower"] = false;
        flags["upper"] = false;
        flags["digit"] = false;
        flags["special"] = false;

        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] >= 'a' || password[i] <= 'z')
                flags["lower"] = true;
            if (password[i] >= 'A' || password[i] <= 'Z')
                flags["upper"] = true;
            if (password[i] >= '0' || password[i] <= '9')
                flags["digit"] = true;
            if (checkSpecial(password[i]))
                flags["special"] = true;
        }

        for (int i = 0; i < password.length() - 1; i++)
            if (password[i] == password[i + 1])
                return false;

        for (auto it : flags)
            if (!it.second)
                return false;
        return true;
    }
};

int main()
{

    return 0;
}