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
vector<vector<int>> res;
queue <TreeNode*> q; 
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return res;
       q.push(root);
       while (!q.empty()){
        int currsize = q.size();
         vector<int> currLevel;
         for (int i = 0; i < currsize; i++){
            TreeNode * tmp =q.front();
            q.pop();
currLevel.push_back(tmp->val);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
}       
         res.push_back(currLevel);
}
       
        return res;
    }
};

