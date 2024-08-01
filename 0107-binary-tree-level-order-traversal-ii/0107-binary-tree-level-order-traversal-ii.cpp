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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector <int>> res;
        if (!root) return res;
        queue <TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            int n = q.size();
            vector <int> currentL;
            for (int i =0; i<n; ++i) {
                TreeNode* current = q.front();
                q.pop();
                currentL.push_back(current->val);
                
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);
            }
            res.push_back(currentL);
        }
        reverse(res.begin() , res.end());
        return res;
    }
};