class Compare
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second < b.second)
            return false;
        if (a.second == b.second)
            return a.first < b.first;

        return true;
    }
};

class Solution
{

public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // profit capital
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        // projects profit which are less than the current capital
        // they are in sorted way so we have to pick the top one
        priority_queue<int> pj;
        int n = profits.size();
        for (int i = 0; i < n; i++)
            pq.push({profits[i], capital[i]});

        // while (!pq.empty())
        // {
        //     auto top = pq.top();
        //     cout << top.first << " " << top.second << endl;
        //     pq.pop();
        // }

        int ans = 0;
        while (k--)
        {
            vector<pair<int, int>> temp;
            while (!pq.empty() && pq.top().second <= w)
            {
                // cout << pq.top().first << " " << pq.top().second << endl;
                pj.push(pq.top().first);
                pq.pop();
            }

            if (pj.empty())
                break;
            w += pj.top();
            pj.pop();
        }

        return w;
    }
};

// class Compare
// {
// public:
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b)
//     {
//         if (a.second < b.second)
//             return false;
//         if (a.second == b.second)
//             return a.first > b.first;
//         return true;
//     }
// };

// class Solution
// {
// public:
//     int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
//     {
//         priority_queue<int> availableProjects;

//         priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
//         int n = profits.size();
//         for (int i = 0; i < n; i++)
//             pq.push({profits[i], capital[i]});

//         for (int i = 0; i < k; i++)
//         {
//             while (!pq.empty() && pq.top().second <= w)
//             {
//                 availableProjects.push(pq.top().first);
//                 pq.pop();
//             }

//             if (availableProjects.empty())
//                 break;

//             w += availableProjects.top();
//             availableProjects.pop();
//         }

//         return w;
//     }
// };
