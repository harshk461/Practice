#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class AllOne
{
private:
    unordered_map<string, int> count;
    map<int, set<string>> freq;

public:
    AllOne() {}

    void inc(string key)
    {
        // Increment the count for the key
        int currFreq = count[key]++;
        // If this key was previously in the map, we need to remove it from the old frequency
        if (currFreq > 0)
        {
            freq[currFreq].erase(key);
            // If there are no keys left at that frequency, remove it from the map
            if (freq[currFreq].empty())
            {
                freq.erase(currFreq);
            }
        }
        // Insert the key into the new frequency set
        freq[currFreq + 1].insert(key);
    }

    void dec(string key)
    {
        // Decrement the count for the key
        int currFreq = count[key]--;
        // Remove the key from the current frequency
        freq[currFreq].erase(key);
        // If there are no keys left at that frequency, remove it from the map
        if (freq[currFreq].empty())
        {
            freq.erase(currFreq);
        }
        // If the frequency is greater than 0, insert it into the next lower frequency
        if (currFreq > 1)
        {
            freq[currFreq - 1].insert(key);
        }
        // If the frequency reaches 0, remove the key from the count map
        if (count[key] == 0)
        {
            count.erase(key);
        }
    }

    string getMaxKey()
    {
        // Check if there are any keys present
        if (freq.empty())
            return "";
        // Return one of the keys with the maximum frequency
        return *(freq.rbegin()->second.begin());
    }

    string getMinKey()
    {
        // Check if there are any keys present
        if (freq.empty())
            return "";
        // Return one of the keys with the minimum frequency
        return *(freq.begin()->second.begin());
    }
};
int main()
{

    return 0;
}