#include <bits/stdc++.h>
using namespace std;

class SegmentTreeSum
{
private:
    vector<int> arr;
    vector<int> seg;

public:
    SegmentTreeSum(vector<int> &nums)
    {
        this->arr = nums;
        if (nums.size() > 0)
            seg.resize(4 * nums.size());
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void query(int node, int start, int end, int l, int r)
    {
        if ()
    }
};

class Solution
{
private:
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        SegmentTreeSum st(nums);
    }
};

int main()
{

    return 0;
}