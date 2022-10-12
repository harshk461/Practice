#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; j++)
        {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        sort(arr.begin(), arr.end());
        for (int k = 1; k < arr.size(); k++)
        {
            if (arr[k] != arr[k - 1])
            {
                cout << arr[k] << endl;
            }
        }
    }
    return 0;
}
