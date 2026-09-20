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
pair<int, int> dfs (TreeNode *root){
    if(!root) return{0, 0};
    int val = root->val;
    
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int rob = val + left.first + right.first;

    int notrob = max (left.first, left.second) + max (right.first, right.second);

    return {notrob, rob};
}
    int rob(TreeNode* root) {

        if(!root) return 0;
        auto p = dfs (root);
       return max(p.first, p.second);
        
    }
};