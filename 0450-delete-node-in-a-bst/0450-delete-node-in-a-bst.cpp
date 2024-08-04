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
private:
    TreeNode* minVal(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL) 
        {current = current->left;}
        return current;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left , key);
        }
       else if (key > root->val) {
            root->right = deleteNode(root->right , key);
        }
        else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
           else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // with 2 children
            TreeNode* temp = minVal(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};