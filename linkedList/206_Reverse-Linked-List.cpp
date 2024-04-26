#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL || head->next == NULL) return head;
        ListNode *next, *previous=NULL;
        while(head!= NULL){
            next=head->next;
            head->next=previous;
            previous=head;
            head=next;
        }
        return previous;
    }
};