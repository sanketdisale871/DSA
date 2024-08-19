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

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }

        if(root->right==NULL){
            return root->left;
        }

        TreeNode* rightNode = root->right;
        TreeNode* lefRighMost = findRightMost(root->left);
        lefRighMost->right = rightNode;

        return root->left;
    }

    TreeNode* findRightMost(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root==NULL){
            return root;
        }

        if(root->val == val){
            return helper(root);
        }

        TreeNode* dummy = root;

        while(root!=NULL){
            if(root->val > val){
                if(root->left && root->left->val == val){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right && root->right->val == val){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }            
        }

        return dummy;
    }
};