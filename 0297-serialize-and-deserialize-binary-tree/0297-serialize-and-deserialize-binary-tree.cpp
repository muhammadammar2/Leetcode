/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root , out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in (data);
        return deserializeHelper(in);
    }
private: 
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "N ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left , out);
        serializeHelper(node->right , out);
        
    }
    TreeNode* deserializeHelper(istringstream& in) {
       string val;
        in >> val;
        if(val == "N") return NULL;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));