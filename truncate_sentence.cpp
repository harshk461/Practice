#include <bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k)
{
    vector<string> arr;
    string word = "";
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || i == s.length())
        {
            arr.push_back(word);
            word = "";
        }
        else
        {
            word = word + s[i];
        }
    }

    string ans = " ";
    for (int i = 0; i < k; i++)
    {
        string temp_ans;
        if (i == k - 1)
        {
            temp_ans = arr[i];
        }
        else
        {
            temp_ans = arr[i] + " ";
        }
        ans.insert(ans.length() - 1, temp_ans);
    }
    trim(ans);
    return ans;
}

void trim(string &s)
{
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
}

int main()
{
    string arr = "Hello how are you Contestant";
    cout << truncateSentence(arr, 3);
    return 0;
}