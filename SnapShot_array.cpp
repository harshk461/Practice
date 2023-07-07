#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    vector<vector<pair<int, int>>> snaps;
    int snap_id = 0;
    SnapshotArray(int length) : snaps(length)
    {
    }

    void set(int index, int val)
    {
        auto &[lastID, lastVal] = snaps[index].back();
        if (lastID == snap_id)
        {
            lastVal = val;
        }
        else
        {
            snaps[index].push_back(make_pair(snap_id, val));
        }
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        vector<pair<int, int>> snap = snaps[index];
        for(auto i:snap){
            if(i.first==snap_id){
                return i.second;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}