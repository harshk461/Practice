#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void flatten(Node *root)
    {
        Node *curr = root;
        while (curr != NULL)
        {

            if (curr->left)
            {
                Node *pred = curr->left;
                while (pred->right)
                {
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        // //left part null
        // curr=root;
        // while(curr!=NULL){
        //     curr->left=NULL;
        //     curr=curr->right;
        // }
    }
};

int main()
{

    return 0;
}