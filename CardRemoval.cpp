#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        int maxc = 0;
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = 0; k < n; k++)
            {
                if (arr[j] == arr[k])
                {
                    count++;
                }
            }
            if (count > maxc)
            {
                maxc = count;
            }
        }
        cout << n - maxc << endl;
    }
    return 0;
}
