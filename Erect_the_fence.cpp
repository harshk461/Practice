#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool pointAboveOrBelow(int x1, int y1, int x2, int y2, int x, int y)
    {
        int s = (y2 - y1) * x + (x1 - x2) * y + (x2 * y1 - x1 * y2);
        // inside
        if (s < 0)
            return false;
        // outsidee
        return true;
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        if (trees.size() <= 3)
            return trees;
        vector<vector<int>> ans;

        int xmin = INT_MAX, xmax = INT_MIN;
        int ymin = INT_MAX, ymax = INT_MIN;

        vector<int> xmin_tree;
        vector<int> xmax_tree;
        vector<int> ymin_tree;
        vector<int> ymax_tree;

        // finding boundary ranges
        for (auto it : trees)
        {
            if (it[0] < xmin)
            {
                xmin = it[0];
                xmin_tree = it;
            }
            if (it[0] > xmax)
            {
                xmax = it[0];
                xmax_tree = it;
            }
            if (it[1] < ymin)
            {
                ymin = it[1];
                ymin_tree = it;
            }
            if (it[1] > ymax)
            {
                ymax = it[1];
                ymax_tree = it;
            }
        }

        set<vector<int>> vis;
        // finding boundary trees
        for (auto it : trees)
        {
            if (it[0] == xmin || it[0] == xmax)
            {
                ans.push_back(it);
                vis.insert(it);
            }
            else if (it[1] == ymin || it[1] == ymax)
            {
                ans.push_back(it);
                vis.insert(it);
            }
        }

        // checking points
        vector<vector<int>> edge = {
            {xmin_tree[0], xmin_tree[1], xmax_tree[0], xmax_tree[1]},
            {xmax_tree[0], ymin_tree[1], xmax_tree[0], ymax_tree[1]},
            {xmax_tree[0], ymax_tree[1], xmin_tree[0], ymax_tree[1]},
            {xmin_tree[0], ymax_tree[1], xmin_tree[0], ymin_tree[1]},
        };

        for (auto it : edge)
        {
            for (auto point : trees)
            {
                if (pointAboveOrBelow(it[0], it[1], it[2], it[3], point[0], point[1]) &&
                    vis.find(point) != vis.end())
                {
                    ans.push_back(point);
                    vis.insert(point);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}