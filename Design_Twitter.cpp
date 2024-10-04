#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    //{user,tweet id}
    vector<pair<int, int>> tweets;
    unordered_map<int, set<int>> users;

public:
    Twitter()
    {
    }

    // void print()
    // {
    //     // for (auto it : tweets)
    //     // {
    //     //     cout << it.first << " " << it.second << endl;
    //     // }
    //     for (auto it : users)
    //     {
    //         cout << it.first << " ";
    //         for (auto i : it.second)
    //             cout << i << " ";
    //         cout << endl;
    //     }
    // }
    void postTweet(int userId, int tweetId)
    {
        cout << userId << " " << tweetId << endl;
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        int n = tweets.size();
        vector<int> ans;
        int i = n - 1;
        int count = 0;
        set<int> followers = users[userId];
        followers.insert(userId);
        while (i >= 0 && count < 10)
        {
            if (followers.find(tweets[i].first) != followers.end())
            {
                ans.push_back(tweets[i].second);
                cout << tweets[i].second << " ";
                count++;
            }
            i--;
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        users[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter t;
    t.postTweet(1, 1);
    t.postTweet(2, 2);
    t.follow(1, 2);
    // for (auto it : t.getNewsFeed(1))
    //     cout << it << " ";
    t.print();
    return 0;
}