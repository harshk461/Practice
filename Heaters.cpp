#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &arr, vector<int> &h)
    {
        set<int> uncovered;

        set<int> A(arr.begin(), arr.end());
        set<int> H(h.begin(), h.end());

        set_difference(A.begin(), A.end(), H.begin(), H.end(), std::inserter(uncovered, uncovered.end()));

        vector<vector<int>> ranges;
        for (auto heater : h)
            ranges.push_back({heater, heater});

        int radius = 0;

        while (uncovered.size() > 0)
        {
            radius++;
            for (auto rng : ranges)
            {
                rng[0]--;
                rng[1]++;
                uncovered.erase(rng[0]);
                uncovered.erase(rng[1]);
            }
        }

        return radius;
    }

    int solve(vector<int> &arr, vector<int> &h)
    {
        int radius = 0;
        for (auto house : arr)
        {
            int min_dist = INT_MAX;
            for (auto heater : h)
                min_dist = min(min_dist, abs(heater - house));
            radius = max(radius, min_dist);
        }

        return radius;
    }

    int binaryUtil(vector<int> &arr, int house)
    {
        int left = 0;
        int right = arr.size() - 1;
        int min_dist = INT_MAX;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            min_dist = min(min_dist, abs(arr[mid] - house));
            if (arr[mid] < house)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return min_dist;
    }

    int binarySol(vector<int> &arr, vector<int> &h)
    {
        sort(h.begin(), h.end());
        int radius = 0;
        for (auto house : arr)
            radius = max(radius, binaryUtil(h, house));

        return radius;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        vector<int> res(houses.size(), INT_MAX);

        // RHS heater
        for (int i = 0, h = 0; i < houses.size() && h < heaters.size();)
        {
            if (houses[i] <= heaters[h])
            {
                res[i] = heaters[h] - houses[i];
                i++;
            }
            else
                h++;
        }

        // LHS heater
        for (int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;)
        {
            if (houses[i] >= heaters[h])
            {
                res[i] = min(res[i], houses[i] - heaters[h]);
                i--;
            }
            else
                h--;
        }

        return brute(houses, heaters);
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 5};
    vector<int> H = {2};
    cout << s.findRadius(A, H);
    return 0;
}