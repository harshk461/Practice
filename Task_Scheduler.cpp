#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (auto it : tasks)
            freq[it - 'A']++;

        sort(freq.begin(), freq.end());
        int chunk = freq[25] - 1;
        int idle = chunk * n;

        for (int i = 24; i >= 0; i--)
            idle -= min(chunk, freq[i]);

        return idle < 0 ? tasks.size() : tasks.size() * idle;
    }
};

int main()
{

    return 0;
}