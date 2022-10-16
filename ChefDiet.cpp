#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        while (n--)
        {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        int count = 0;
        int protein = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[i] + protein) >= k)
            {
                protein += arr[i] - k;
                count++;
            }
            else
            {
                cout << "No " << i + 1 << endl;
                break;
            }
        }
        if (count == arr.size())
        {
            cout << "Yes" << endl;
            break;
        }
    }
    return 0;
}
