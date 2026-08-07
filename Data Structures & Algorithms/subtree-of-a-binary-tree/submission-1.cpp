/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;z
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode *root, TreeNode *subRoot){
        if (!root && ! subRoot) return true;
        else if (!root || !subRoot) return false;
        if(root->val != subRoot-> val) return false;
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
            }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true;
        if(isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot)) return true;
        return false;
        
        

    }
};
