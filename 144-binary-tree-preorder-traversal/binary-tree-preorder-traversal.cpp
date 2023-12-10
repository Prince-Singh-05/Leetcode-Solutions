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

    void preOrder(TreeNode* root, vector<int> &ans) {
        // NLR

        // base case
        if(root == nullptr) {
            return;
        }

        // N
        ans.push_back(root->val);

        // L
        preOrder(root->left, ans);

        // R
        preOrder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        preOrder(root, ans);
        return ans;

    }
};