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

    vector<int> ans;

    void postOrder(TreeNode* root, vector<int> &ans) {
        // LRN

        // base case
        if(root == nullptr) {
            return;
        }

        // L
        postOrder(root->left, ans);

        // R
        postOrder(root->right, ans);

        // N
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root, ans);
        return ans;    
    }
};