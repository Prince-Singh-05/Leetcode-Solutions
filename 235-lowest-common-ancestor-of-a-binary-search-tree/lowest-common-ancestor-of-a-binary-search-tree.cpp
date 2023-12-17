/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;

        // case 1 - p & q are in left sub tree of root node
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        // case 2 - p & q are in right sub tree of root node
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // // case 3 - p is in left sub tree & q is in right sub tree
        // if(p->val < root->val && q->val > root->val) {
        //     return root;
        // }

        // // case 4 - p is in right sub tree & q is in left sub tree
        // if(p->val > root->val && q->val < root->val) {
        //     return root;
        // }

        return root;
    }
};