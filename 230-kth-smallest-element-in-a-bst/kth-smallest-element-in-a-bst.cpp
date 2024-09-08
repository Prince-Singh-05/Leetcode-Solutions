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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodeArray;
        inorder(root, nodeArray);
        return nodeArray[k-1];
    }

private: 
    void inorder(TreeNode* root, vector<int>& nodeArray) {
        if(root == NULL) return;

        inorder(root->left, nodeArray);
        nodeArray.push_back(root->val);
        inorder(root->right, nodeArray);
    }
};