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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue <pair <TreeNode* ,  int>> q;
        q.push({root , root->val});
        while (q.empty() == false) {
            auto[node , currentSum] = q.front();
            q.pop();
            
            if (node->left == NULL && node->right == NULL) {
                if (currentSum == targetSum) return true;
            }
            if (node->left != NULL) {
                q.push({node->left , currentSum + node->left->val});
            }
            if (node->right != NULL) {
                q.push({node->right , currentSum + node->right->val});
            }
        }
        return false;
    }
};