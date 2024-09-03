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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        trackParent(root, parentMap);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int curLevel = 0;

        while (!q.empty()) {
            if (curLevel == k) break;

            int sz = q.size();
            while (sz-- > 0) {
                TreeNode* nd = q.front(); q.pop();
                if (nd->left && visited.find(nd->left) == visited.end()) {
                    visited.insert(nd->left);
                    q.push(nd->left);
                }
                if (nd->right && visited.find(nd->right) == visited.end()) {
                    visited.insert(nd->right);
                    q.push(nd->right);
                }
                if (parentMap[nd] && visited.find(parentMap[nd]) == visited.end()) {
                    visited.insert(parentMap[nd]);
                    q.push(parentMap[nd]);
                }
            }
            curLevel++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val); 
            q.pop();
        }
        return ans;
    }

private:
    void trackParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if(root == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = NULL;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left != NULL) {
                q.push(node->left);
                parentMap[node->left] = node;
            }

            if(node->right != NULL) {
                q.push(node->right);
                parentMap[node->right] = node;
            }
        }
    }
};