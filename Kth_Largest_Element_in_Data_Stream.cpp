#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
private:
    void heapify(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
    }

public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (auto i : nums)
            heapify(i);
    }

    int add(int val)
    {
        heapify(val);
        return pq.top();
    }
};

int main()
{
cout<<"sjd";
    return 0;
}