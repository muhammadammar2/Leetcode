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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL ,
        *second = NULL ,
        *prev = NULL ,
        *predecessor = NULL;
        
        TreeNode* current = root;
        while (current != NULL) {
            if (current->left == NULL) {
                if (prev && prev->val > current->val) {
                    if (!first) first = prev;
                    second = current;
                }
                prev = current;
                current = current->right;
            }
            else {
                predecessor = current->left;
                while (predecessor->right != NULL && predecessor-> right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    predecessor->right = NULL;
                    if (prev && prev->val > current->val) {
                        if (!first) first = prev;
                        second = current;
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }
        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};