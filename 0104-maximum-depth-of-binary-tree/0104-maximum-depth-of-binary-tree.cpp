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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cc = 0;
        while (!q.empty()) {
            int n = q.size();
            cc++;
            for (int i = 0; i<n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left !=NULL) q.push(curr->left);
                if (curr->right !=NULL) q.push(curr->right);
            }
        }
        return cc;
    }
};