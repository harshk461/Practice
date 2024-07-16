class Compare
{
public:
    bool operator()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
    {
        if (a.first.first < b.first.first)
            return true;
        else if (a.first.first == b.first.first)
            return a.first.second < b.first.second;

        return false;
    }
};

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<pair<int, int>, int>> arr;
        int n = trips.size();
        for (int i = 0; i < n; i++)
        {
            int from = trips[i][1];
            int to = trips[i][2];
            int cap = trips[i][0];

            arr.push_back(make_pair(make_pair(from, to), cap));
        }

        sort(arr.begin(), arr.end(), Compare());

        // for (auto it : arr)
        //     cout << it.first.first << "-" << it.first.second << "->" << it.second << endl;

        vector<int> cost(1000, 0);

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int from = arr[i].first.first;
            int to = arr[i].first.second;
            int cap = arr[i].second;

            for (int j = from; j <= to; j++)
            {
                cost[j] += cap;
                if (cost[j] > capacity)
                    ans = false;
            }
        }

        for (auto it : cost)
            cout << it << " ";
        return ans;
    }
};