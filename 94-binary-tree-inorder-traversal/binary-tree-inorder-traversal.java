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
    List<Integer>lst = new ArrayList<>();

    public void traverselist(TreeNode root,List<Integer>lst){
        if(root==null){
            return;
        }
        traverselist(root.left,lst);
        lst.add(root.val);
        traverselist(root.right,lst);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        // Inorder Traversal => Left-Root-Right 
        traverselist(root,lst);
        // List<Integer>lst = new ArrayList<>();

        return lst;
    }
}