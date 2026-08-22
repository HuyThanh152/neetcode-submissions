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
int res = 0;
void help (TreeNode* root, int prev){
    if(!root) return;
    int curr = root->val;
    if (curr >= prev){ res++;
     prev = curr;}
    help (root->left, prev);
    help (root->right, prev);

}
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        help(root, root->val);
        return res;
        
    }
};
