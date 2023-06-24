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

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* prev=head;
    ListNode* curr=head->next;
    while(curr!=NULL){
        if(prev->val==curr->val){
            curr=curr->next;
        }
        else{
            prev->next=curr;
            prev=curr;
            curr=prev->next;
        }
    }
    prev->next=NULL;
    return head;
}

int main()
{

    return 0;
}