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
        if (!root) return 0;
        stack<pair <TreeNode* , int>>s;
        s.push({root , root->val});
        int c = 0;
        while (s.empty() == false) {
            auto [node , maxSoF] = s.top();
            s.pop();
            if (node->val >= maxSoF) {
                c++;
            }
            if (node->left) {
                s.push({node->left , max(maxSoF, node->val)});
            }
            if (node->right) {
                s.push({node->right , max(maxSoF, node->val)});
            }
        }
        return c;
    }
};