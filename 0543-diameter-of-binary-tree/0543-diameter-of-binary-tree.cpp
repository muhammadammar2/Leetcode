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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        cal(root , d);
        return d;
    }
    int cal (TreeNode* node ,int& d) {
        if (!node) return 0;
        int L = cal (node->left, d);
        int R = cal (node->right , d);
        d = max(d , L + R);
        return max (L , R) + 1;
    }
};