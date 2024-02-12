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
    int findLefHt(TreeNode*root){
        int lHt = 0;

        while(root->left!=NULL){
            root = root->left;
            lHt++;
        }
        return lHt;
    }

    int findRightHt(TreeNode*root)
    {
        int rHt = 0;

        while(root->right!=NULL){
            root = root->right;
            rHt++;
        }

        return rHt;
    }

public:
    int countNodes(TreeNode* root) {
        // if 
        if(root == NULL){
            return 0;
        }

        int lHt = findLefHt(root);
        int rHt = findRightHt(root);

        if(lHt==rHt){
            return (1<<(lHt+1))-1;
        }

        int lefNodes = countNodes(root->left);
        int rigNodes = countNodes(root->right);

        return lefNodes+rigNodes+1;
    }
};