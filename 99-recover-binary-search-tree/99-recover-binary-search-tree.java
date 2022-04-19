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
    TreeNode firstMistake, secondMistake, prev;
    public void recoverTree(TreeNode root) {
        prev = new TreeNode(Integer.MIN_VALUE);
        
        inorder(root);
        
        swap(firstMistake, secondMistake);
    }
    
    void inorder(TreeNode root) {
        if(root == null)
            return;
        
        inorder(root.left);
        
        if(firstMistake == null && root.val < prev.val)
            firstMistake = prev;
        if(firstMistake != null && root.val < prev.val)
            secondMistake = root;
        
        prev = root;
        
        inorder(root.right);
    }
    
    void swap(TreeNode firstMistake, TreeNode secondMistake) {
        int temp = secondMistake.val;
        secondMistake.val = firstMistake.val;
        firstMistake.val = temp;
    }
}