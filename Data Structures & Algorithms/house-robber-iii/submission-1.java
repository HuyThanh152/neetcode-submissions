/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int [] dfs(TreeNode root){
        if (root == null) return new int[] {0,0};
        int val = root.val;

        int[] l =  dfs(root.left);
        int[] r =  dfs(root.right);
        
        int rob =  (val + l[0] + r[0]);

    int notrob =  Math.max (l[0], l[1]) + Math.max (r[0], r[1]);

    return new int[] {notrob, rob};
        
            }
    public int rob(TreeNode root) {
        int [] res = dfs(root);
        return Math.max(res[0], res[1]);
    }
}