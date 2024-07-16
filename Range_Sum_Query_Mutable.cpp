#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> a, seg;

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            seg[node] = a[start];
            return;
        }

        int mid = (start + end) >> 1;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            a[idx] = val;
            seg[node] = val;
            return;
        }

        int mid = (start + end) >> 1;
        if (idx >= start && idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, end, idx, val);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int sumRange(int node, int start, int end, int L, int R)
    {
        if (R < start || end < L)
        {
            return 0;
        }
        if (L <= start && end <= R)
        {
            return seg[node];
        }

        int mid = (start + end) >> 1;
        int left_sum = sumRange(2 * node + 1, start, mid, L, R);
        int right_sum = sumRange(2 * node + 2, mid + 1, end, L, R);
        return left_sum + right_sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        this->a = nums;
        if (!a.empty())
        {
            this->seg = vector<int>(4 * a.size());
            build(0, 0, a.size() - 1);
        }
    }

    void update(int index, int val)
    {
        if (!a.empty())
        {
            update(0, 0, a.size() - 1, index, val);
        }
    }

    int sumRange(int left, int right)
    {
        if (a.empty())
        {
            return 0;
        }
        return sumRange(0, 0, a.size() - 1, left, right);
    }
};

int main()
{

    return 0;
}