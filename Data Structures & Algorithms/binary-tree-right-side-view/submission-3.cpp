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
vector<int> res;
queue <TreeNode*> q; 
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            int currsize = q.size();
           
            for (int i = 0; i < currsize; i++){
                TreeNode *tmp = q.front();
                q.pop();
if(i == currsize - 1)
                 res.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
           
           
        }
        return res;
    }
};
