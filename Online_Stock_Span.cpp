#include <bits/stdc++.h>
using namespace std;

// class StockSpanner
// {
// public:
//     stack<int> q;
//     StockSpanner()
//     {
//     }

//     int next(int price)
//     {
//         if (q.empty())
//         {
//             q.push(price);
//             return 1;
//         }
//         else
//         {
//             queue<int> temp;
//             int count = 0;
//             while (!q.empty())
//             {
//                 int top = q.front();
//                 if (top <= price)
//                     count++;
//                 temp.push(top);
//                 q.pop();
//             }

//             while (!temp.empty())
//             {
//                 q.push(temp.front());
//                 temp.pop();
//             }

//             return count;
//         }
//     }
// };

class StockSpanner
{
public:
    // num->count
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int count = 0;
        while (!st.empty() && st.top() <= price)
        {
            count++;
            st.pop();
        }

        st.push({price, count});
        return count;
    }
};

int main()
{

    return 0;
}