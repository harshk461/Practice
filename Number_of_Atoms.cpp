#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string getElement(int &i, string &str)
    {
        string ans = "";
        int n = str.length();
        ans += str[i]; // adding first capital letter
        i++;
        while (i < n && (str[i] >= 'a' && str[i] <= 'z'))
            ans += str[i++];

        return ans;
    }

    int getNumber(int &i, string &str)
    {
        string ans = "";
        while (i < str.length() && (str[i] >= '0' && str[i] <= '9'))
            ans += str[i++];

        if (ans.size() > 0)
            return stoi(ans);
        return 1;
    }

public:
    string countOfAtoms(string formula)
    {
        stack<map<string, int>> st;
        int n = formula.length();
        int i = 0;

        map<string, int> mp;
        st.push(mp);

        while (i < n)
        {
            if (formula[i] >= 'A' && formula[i] <= 'Z')
            {
                string element = getElement(i, formula);
                int number = getNumber(i, formula);
                // current parentheses
                st.top()[element] += number;
            }
            if (formula[i] == '(')
            {
                // start new map which contains all new elements inside the parenthese
                map<string, int> temp;
                st.push(temp);
                i++;
            }
            else if (formula[i] == ')')
            {
                i++;
                int number = getNumber(i, formula);

                map<string, int> top = st.top();
                st.pop();

                for (auto it : top)
                    st.top()[it.first] += (it.second * number);
            }
        }

        string ans = "";
        for (auto it : st.top())
        {
            ans += it.first;
            if (it.second > 1)
                ans += to_string(it.second);
        }

        return ans;
    }
};

int main()
{

    return 0;
}