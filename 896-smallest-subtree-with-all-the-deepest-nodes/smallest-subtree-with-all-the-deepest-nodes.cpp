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
    int findHt(TreeNode*root){
        // Base case
        if(root == NULL){
            return 0;
        }

        int lHt = findHt(root->left);
        int rHt = findHt(root->right);

        return 1+max(lHt,rHt);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        int lHt = findHt(root->left);
        int rHt = findHt(root->right);

        if(lHt==rHt){
            return root;
        }

        if(lHt<rHt){
            return subtreeWithAllDeepest(root->right);
        }
        else{
            return subtreeWithAllDeepest(root->left);
        }
    }
};