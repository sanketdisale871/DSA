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

    bool isLeafNode(TreeNode* node){
        if(node->left == NULL && node->right == NULL){
            return true;
        }
        return false;
    }

    void doPostOrderTraversal(TreeNode* root,int target){
        // base case 
        if(root==NULL){
            return ;
        }
        
        doPostOrderTraversal(root->left,target);
        doPostOrderTraversal(root->right,target);

        if(root->left && isLeafNode(root->left)){
            if(root->left->val == target){
                root->left = NULL;
            }
        }

        if(root->right && isLeafNode(root->right)){
            if(root->right->val == target){
                root->right = NULL;
            }
        }        

    }
    
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        doPostOrderTraversal(root,target);

        if(isLeafNode(root) && root->val == target){
            return NULL;
        }

       return root;

        
    }
};