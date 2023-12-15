#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<string> &garbage, vector<int> &travel)
    {
        int ans = 0;
        int n = garbage.size();
        bool m = false, p = false, g = false;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!g && garbage[i].find('G') != garbage[i].end())
            {
                g = true;
                ans += accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (!m && garbage[i].find('M') != garbage[i].end())
            {
                m = true;
                ans += accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (!p && garbage[i].find('M') != garbage[i].end())
            {
                p = true;
                ans += accumulate(travel.begin(), travel.begin() + i, 0);
            }

            if (m && p && g)
                break;
        }

        return ans + accumulate(garbage.begin(), garbage.end(), 0, [](int sum, const string &str)
                                { return sum + str.size(); })
    }

public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> prefixSum(travel.size() + 1, 0);
        prefixSum[1] = travel[0];
        for (int i = 1; i < travel.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + travel[i];

        unordered_map<char, int> garbageLastPos;

        unordered_map<char, int> garbageCount;

        for (int i = 0; i < garbage.size(); i++)
        {
            for (auto c : garbage[i])
            {
                garbageLastPos[c] = i;
                garbageCount[c]++;
            }
        }

        char garbageType[3] = {'M', 'P', 'G'};
        int ans = 0;

        for (auto c : garbageType)
        {
            if (garbageCount[c])
                ans += prefixSum[garbageLastPos[c]] + garbageCount[c];
        }

        return ans;
    }
};

class Solution
{
public:
    int garbageCollection(std::vector<std::string> &garbage, std::vector<int> &travel)
    {
        int ans = 0;
        int n = garbage.size();
        bool m = false, p = false, g = false;
        for (int i = n - 1; i >= 0; --i)
        {
            if (!g && garbage[i].find('G') != std::string::npos)
            {
                g = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (!m && garbage[i].find('M') != std::string::npos)
            {
                m = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (!p && garbage[i].find('P') != std::string::npos)
            {
                p = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (m && p && g)
            {
                break;
            }
        }
        return ans + std::accumulate(garbage.begin(), garbage.end(), 0, [](int sum, const std::string &str)
                                     { return sum + str.size(); });
    }
};

int main()
{

    return 0;
}