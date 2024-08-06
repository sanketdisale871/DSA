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
    int dia=0 ;

    int findHt(TreeNode* root){
        // Base case 
        if(root==NULL){
            return 0;
        }

        int lef = findHt(root->left);
        int rig = findHt(root->right);

        dia = max(dia,lef+rig);

        return 1+max(lef,rig);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        findHt(root);
        return dia;
    }
};