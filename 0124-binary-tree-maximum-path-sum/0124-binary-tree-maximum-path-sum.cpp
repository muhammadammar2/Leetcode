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
    int maxPathSum(TreeNode* root) {
     int maxSum = INT_MIN;
        maxPathDown (root , maxSum);
        return maxSum;
    }
private: 
    int maxPathDown (TreeNode* node , int& maxSum) {
        if (node == NULL) return 0;
        
        //0 is for negative paths
        int leftMax = max (0 , maxPathDown (node->left , maxSum));
        int rightMax = max (0 , maxPathDown (node->right , maxSum));
        
        int currentSum = leftMax + rightMax + node->val;
        
        maxSum = max (maxSum , currentSum);
        
        return max (leftMax , rightMax) + node->val;
    }
};