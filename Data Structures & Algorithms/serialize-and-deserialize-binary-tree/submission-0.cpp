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

class Codec {
public:
string res = "";
void build (TreeNode* root){
    if(!root) {
        res+= "N,";
        return;
        }
    if(root) res += to_string(root->val) +",";
    
    build (root->left);
    build(root->right);
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        build(root);
        return res;    
    }
    TreeNode *buildTree (stringstream &res){
        string val;
        if (!getline(res, val, ',')) return NULL;
        if (val == "N") return NULL;

        TreeNode *root = new TreeNode (stoi(val));
        root->left = buildTree(res);
        root->right = buildTree(res);
        return root;    
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);        
    }
};
