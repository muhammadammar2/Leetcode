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

    //dfs reccursive

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//      int count =0;
//         int result = 0;
//         inOrder(root , count , k , result);
//         return result;
//     }
// private: 
//     void inOrder (TreeNode* node, int& count, int k , int& result) {
//         if (!node) return;
//         //visiting left
//         inOrder (node->left , count , k , result);
        
//         count++;
//         if (count == k) {
//             result = node->val;
//             return;
//         }
//         //visiting right
//         inOrder (node->right , count , k , result);
//     }
// };

   //dfs iterative

class Solution {
public: 
    int kthSmallest(TreeNode* root , int k) {
    stack <TreeNode*> s;
        TreeNode* node = root;
        int count = 0;
        
        while (!s.empty() || node!=NULL) {
            while (node!=NULL) {
                s.push(node);
                node = node->left; //now at left
            }
            //node must be the leftmost node
            node = s.top();
            s.pop();
            
            if (++count == k) {
                return node->val;
            }
            node = node->right;
        }
        return -1; 
    }
    
};