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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == NULL) return -1;
        if(root->left->val == root->right->val){
            int left_second = findSecondMinimumValue(root->left);
            int right_second = findSecondMinimumValue(root->right);
            if(left_second==-1 && right_second!=-1) return right_second;
            else if(left_second!=-1 && right_second==-1) return left_second;
            return min(left_second,right_second);
        }
        else if(root->left->val < root->right->val){
            int left_second = findSecondMinimumValue(root->left);
            if(left_second ==-1) return root->right->val;
            else return min(left_second,root->right->val);
        }
        else{
            int right_second = findSecondMinimumValue(root->right);
            if(right_second == -1) return root->left->val;
            else return min(right_second,root->left->val);
        }
    }
};