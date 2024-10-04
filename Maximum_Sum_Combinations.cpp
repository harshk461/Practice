#include <bits/stdc++.h>
using namespace std;

vector<int> KMaxCombinations(vector<int> &A, vector<int> &B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    int N = A.size();

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> my_set;

    pq.push(make_pair(A[N - 1] + B[N - 1],
                      make_pair(N - 1, N - 1)));

    my_set.insert(make_pair(N - 1, N - 1));
    for (int count = 0; count < K; count++)
    {

        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if (i - 1 >= 0)
        {
            int sum = A[i - 1] + B[j];

            pair<int, int> temp1 = make_pair(i - 1, j);

            if (my_set.find(temp1) == my_set.end())
            {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }

        if (j - 1 >= 0)
        {
            int sum = A[i] + B[j - 1];
            pair<int, int> temp1 = make_pair(i, j - 1);

            if (my_set.find(temp1) == my_set.end())
            {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
    }
    return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    vector<int> temp = KMaxCombinations(A, B, C);
    return temp;
}
int main()
{
    vector<int> a = {1, 4, 2, 3};
    vector<int> b = {2, 5, 1, 6};

    vector<int> ans = solve(a, b, 4);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}