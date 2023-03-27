#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }

        if (r1 == NULL && r2 != NULL)
        {
            return false;
        }

        if (r1 != NULL && r2 == NULL)
        {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);

        bool currValue = r1->data == r2->data;

        if (left && right && currValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}