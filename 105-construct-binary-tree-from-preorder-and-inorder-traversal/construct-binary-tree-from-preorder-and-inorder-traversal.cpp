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

    int searchInOrder(vector<int> inorder, int size, int target) {
        for(int i = 0; i<size; i++) {
            if(inorder[i] == target) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStart, int inorderEnd, int size) {

        // base case
        if(preIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        // finding root of the tree
        int element = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(element);

        int position = searchInOrder(inorder, size, element);

        root->left = solve(preorder, inorder, preIndex, inorderStart, position-1, size);
        root->right = solve(preorder, inorder, preIndex, position + 1, inorderEnd, size);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        TreeNode* root = solve(preorder, inorder, preIndex, inorderStart, inorderEnd, size);
        return root;

    }
};