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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        if (!root) return res;
        queue <TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            vector <int> curr;
            int n = q.size();
            for (int i =0; i<n ; i++) {
                TreeNode* currr = q.front();
                q.pop();
                curr.push_back(currr->val);
                
                if (currr->left != NULL) q.push(currr->left);
                if (currr->right != NULL) q.push(currr->right);
            }
            res.push_back(curr);
        }
        return res;
    }
};