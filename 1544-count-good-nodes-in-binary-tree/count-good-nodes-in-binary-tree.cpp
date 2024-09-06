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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solveDFS(root, ans, root->val);
        return ans;
    }

private:
    void solveDFS(TreeNode* root, int& ans, int maxValue) {
        if(root == NULL) return;

        if(root->val >= maxValue) {
            ans += 1;
        }

        maxValue = max(maxValue, root->val);

        solveDFS(root->left, ans, maxValue);
        solveDFS(root->right, ans, maxValue);
    }
};