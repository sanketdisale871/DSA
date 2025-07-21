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
    boolean ans = false;
    public void checkPathSum(TreeNode root,int targetSum){
        if(root==null){
            return;
        }

        if(root.left == null && root.right==null){
            if(targetSum-root.val ==0){
                ans = true;
            }
            return;
        }

        checkPathSum(root.left,targetSum-root.val);
        checkPathSum(root.right,targetSum-root.val);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
       /*
       What should I have to do? 
       -> Root -> leaf   ===> targetSum honi chahiye.        
        */
        // int[] arr = new int[5];


        checkPathSum(root,targetSum);
        return ans;
    }
}