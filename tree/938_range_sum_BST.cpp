#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int left,right,ans;
        if(root==NULL) return 0;
        int current_val = root->val;
        left = rangeSumBST(root->left, low, high);
        right = rangeSumBST(root->right, low, high);
        ans = left+right;
        if(current_val<=high && current_val>=low) return ans+current_val;
        else return ans;
    }
};