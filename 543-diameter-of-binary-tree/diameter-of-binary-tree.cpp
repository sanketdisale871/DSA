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
    int dia = 0;
    int findH(TreeNode* root){
        if(root==NULL){
                    return 0;
                }

        if(root->left==NULL && root->right==NULL){
            return 1;
        }

        int lef = findH(root->left);
        int rig = findH(root->right);

        dia = max(dia,lef+rig);


        return 1+max(lef,rig);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        findH(root);

        return dia;

    }
};