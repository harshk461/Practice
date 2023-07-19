#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                          vector<vector<int>> &friends, int id, int level)
    {
        // vector<string> ans;
        // vector<bool> visited(friends.size());
        // visited[id] = true;
        // queue<int> queue{{id}};
        // unordered_map<string, int> count;
        // set<pair<int, string>> freqAndVideo;

        // for (int i = 0; i < level; ++i)
        //     for (int j = queue.size(); j > 0; --j)
        //     {
        //         for (int f : friends[queue.front()])
        //             if (visited[f] == false)
        //             {
        //                 visited[f] = true;
        //                 queue.push(f);
        //             }
        //         queue.pop();
        //     }

        // for (int i = queue.size(); i > 0; --i)
        // {
        //     for (const string &video : watchedVideos[queue.front()])
        //         ++count[video];
        //     queue.pop();
        // }

        // for (const auto [video, freq] : count)
        //     freqAndVideo.insert({freq, video});

        // for (const auto [_, video] : freqAndVideo)
        //     ans.push_back(video);

        // return ans;

        unordered_map<string, int> videos;
        // value->level
        queue<pair<int, int>> q;
        int n = friends.size();
        q.push({id, 0});
        vector<bool> vis(105);
        vis[id] = true;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.second == level)
            {
                for (string i : watchedVideos[p.first])
                    videos[i]++;
                continue;
            }

            for (auto nbr : friends[p.first])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = true;
                    q.push({nbr, p.second + 1});
                }
            }
        }
        vector<pair<int, string>> movies;
        vector<string> ans;
        for (auto i : videos)
            movies.push_back({i.second, i.first});
        sort(movies.begin(), movies.end());
        for (auto i : movies)
            ans.push_back(i.second);
        return ans;
    }
};

int main()
{

    return 0;
}