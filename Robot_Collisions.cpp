#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<vector<int>> robots;
        for (int i = 0; i < n; i++)
            robots.push_back({positions[i], healths[i], directions[i, i]});

        sort(robots.begin(), robots.end());

        vector<vector<int>> st;

        for (auto robo : robots)
        {
            if (st.empty() || st.back()[2] == 'L' || robo[2] == 'R')
                st.push_back(robo);

            if (robo[2] == 'L')
            {
                while (!st.empty() && st.back[2] == 'R')
                {
                    // last position
                    int health = st.back()[1];

                    if (robo[1] > health)
                    {
                        st.pop_back();
                        robo[1] -= 1;
                    }
                    else if (robo[1] < health)
                    {
                        st.back()[1] -= 1;
                        break;
                    }
                    else
                    {
                        // equal health and opposite direction
                        st.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        // sorting array on the basis of index
        sort(st.begin(), st.end().[&](const vector<int> &a, const vector<int> &b)
                         { return a[3] < b[3]; });

        for (auto it : st)
            ans.push_back(it);

        return ans;
    }
};

int main()
{

    return 0;
}