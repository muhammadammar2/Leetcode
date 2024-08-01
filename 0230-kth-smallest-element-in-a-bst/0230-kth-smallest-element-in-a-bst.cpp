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
        if (!root) return true;
        TreeNode* current = root;
        int c = 0;
        stack<TreeNode*> s;
        while(s.empty() == false || current != NULL) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            c++;
            if (c == k) {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};