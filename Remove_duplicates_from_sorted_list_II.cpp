#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* curr=dummy;

    int duplicate;
    while(curr->next && curr->next->next){
        if(curr->next->val==curr->next->next->val){
            duplicate=curr->next->val;
            while(curr->next && curr->next->val==duplicate){
                curr->next=curr->next->next;
            }
        }
        else{
            curr=curr->next;
        }
    }
    return dummy->next
}

int main()
{

    return 0;
}