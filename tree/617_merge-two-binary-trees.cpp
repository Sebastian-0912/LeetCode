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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* merge_root;
        if (root1 == NULL && root2 == NULL)
            return NULL;
        else if (root1 == NULL && root2 != NULL) {
            merge_root = root2;
            merge_root->left = mergeTrees(NULL, root2->left);
            merge_root->right = mergeTrees(NULL, root2->right);
        } else if (root1 != NULL && root2 == NULL) {
            merge_root = root1;
            merge_root->left = mergeTrees(root1->left, NULL);
            merge_root->right = mergeTrees(root1->right, NULL);
        } else if (root1 != NULL && root2 != NULL) {
            merge_root = new TreeNode(root1->val + root2->val) ;
            merge_root->left = mergeTrees(root1->left, root2->left);
            merge_root->right = mergeTrees(root1->right, root2->right);
        }
        return merge_root;
    }
};