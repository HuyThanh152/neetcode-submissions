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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Trường hợp 1: Node lá hoặc chỉ có 1 con
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Trường hợp 2: Node có đủ 2 con
            // Tìm node nhỏ nhất ở nhánh bên phải (Inorder Successor)
            TreeNode* curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }
            // Thay giá trị của root bằng giá trị nhỏ nhất vừa tìm được
            root->val = curr->val;
            // Xóa node trùng giá trị đó ở nhánh bên phải
            root->right = deleteNode(root->right, curr->val);
        }
        return root;
    }
};