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
    private:
    int sum = 0;
    void traversal(TreeNode* root,int low,int high){
        if(root==NULL){
            return;
        }

        if(root->val >= low && root->val<=high){
            sum+=root->val;
        }
        traversal(root->left,low,high);
        traversal(root->right,low,high);
    }
public:
    
    int rangeSumBST(TreeNode* root, int low, int high) {

       traversal(root,low,high);
       return sum;
    }
};