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
    //just return 
    //0 : not covered
    //1 : covered by a camera on its child
    //2 : has a camera
    int dfs (TreeNode* node , int& cameras){
     if (!node) return 1;
        int left = dfs(node->left , cameras);
        int right = dfs(node->right , cameras);
        
        if (left == 0 || right == 0) { // if no child has convered with a camera
            cameras ++;
            return 2;
        } 
        
        if (left == 2 || right == 2) { // if any child has a camera then the node is covered
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root , cameras) == 0) cameras ++;
        return cameras;
    }
};