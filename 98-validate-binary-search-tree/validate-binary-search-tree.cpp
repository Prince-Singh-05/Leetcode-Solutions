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

    bool solve(long long int lb, long long int ub, TreeNode* root) {
        
        if(root == NULL) {
            return true;
        }

        bool cnd1 = (root->val) > lb;
        bool cnd2 = (root->val) < ub;
        bool leftAns = solve(lb, root->val, root->left);
        bool  rightAns = solve(root->val, ub, root->right);

        return cnd1 && cnd2 && leftAns && rightAns;
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerbound = -2147483658;
        long long int upperbound = 2147483658;

        bool isBST = solve(lowerbound, upperbound, root);
        return isBST;
    }
};