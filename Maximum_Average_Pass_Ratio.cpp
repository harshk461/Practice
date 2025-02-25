#include <bits/stdc++.h>
using namespace std;

// Prioritize the class where adding a student yields the largest improvement in the average ratio
typedef pair<double, pair<int, int>> pi;
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pi> pq;

        for (auto &it : classes)
        {
            int u = it[0];
            int v = it[1];
            double improvement = (double)(u + 1) / (v + 1) - (double)u / v;
            pq.push({improvement, {u, v}});
        }

        // Distribute extra students
        while (extraStudents--)
        {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;

            pass++;
            total++;

            double new_improvement = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({new_improvement, {pass, total}});
        }

        // Calculate final average
        double sum = 0;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};

int main()
{

    return 0;
}