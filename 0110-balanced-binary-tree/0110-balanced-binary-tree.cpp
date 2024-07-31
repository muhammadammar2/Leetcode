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
    bool isBalanced(TreeNode* root) {
     return cal(root)!= -1;   
    }
    int cal (TreeNode* node) {
        if (!node) return 0;
        int L = cal(node->left);
        if (L == -1) return -1;
        int R = cal (node->right);
        if (R == - 1)return -1;
        if (abs (L - R) > 1) return -1;
        return max (L , R) + 1;
    }
};