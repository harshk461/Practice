#include <bits/stdc++.h>
using namespace std;

class AllOne
{
private:
    int getCount(string s)
    {
        set<char> st;
        for (auto i : s)
            st.insert(i);
        return st.size();
    }

public:
    unordered_map<string, int> map;
    AllOne() {}

    void inc(string key)
    {
        if (map[key])
            map[key]++;
        else
            map[key] = 1;
    }

    void dec(string key)
    {
        if (map[key])
            map[key]--;
            if(map[key]==0){
                map.erase(key);
            }
        else
            map[key] = 0;
    }

    string getMaxKey()
    {
        int maxkey = INT_MIN;
        string ans = "";
        for (auto i : map)
        {
            if (i.second > maxkey)
            {
                maxkey = i.second;
                ans = i.first;
            }
        }
        return ans;
    }

    string getMinKey()
    {
        int minkey = INT_MAX;
        string ans = "";
        for (auto i : map)
        {
            if (i.second < minkey)
            {
                minkey = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
int main()
{
    unordered_map<string, int> map;
    map["a"] = 2;
    map["b"] = 3;
    return 0;
}