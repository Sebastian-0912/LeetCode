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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans = {};
        if(root==NULL) return ans;
        if (root->left == NULL && root->right == NULL) {
            ans.insert(ans.begin(), root->val);
            return ans;
        } else if (root->left != NULL && root->right == NULL) {
            ans = largestValues(root->left);
            ans.insert(ans.begin(), root->val);
            return ans;
        } else if (root->left == NULL && root->right != NULL) {
            ans = largestValues(root->right);
            ans.insert(ans.begin(), root->val);
            return ans;
        } else {
            vector<int> left = largestValues(root->left);
            vector<int> right = largestValues(root->right);
            if (left.size() >= right.size())
                ans = merge(left, right);
            else
                ans = merge(right, left);
            ans.insert(ans.begin(), root->val);
            return ans;
        }
    }
    vector<int> merge(vector<int> long_vec, vector<int> short_vec) {
        int len = short_vec.size();
        for (int i = 0; i < len; ++i) {
            if (long_vec[i] < short_vec[i])
                long_vec[i] = short_vec[i];
        }
        return long_vec;
    }
};