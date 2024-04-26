#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> forward,backward;
        while(head!=NULL){
            forward.push_back(head->val);
            head=head->next;
        }
        backward=forward;
        reverse(backward.begin(),backward.end());
        if(backward==forward) return true;
        return false;
    }
};