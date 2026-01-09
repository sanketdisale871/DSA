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
    int findHt(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lefHt = findHt(root->left);
        int rigHt = findHt(root->right);

        return 1+max(lefHt,rigHt);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        auto lefHt = findHt(root->left);
        auto rigHt = findHt(root->right);

        if(lefHt==rigHt){
            return root;
        }
        else if(lefHt<rigHt){
            return subtreeWithAllDeepest(root->right);
        }
        else{
            return subtreeWithAllDeepest(root->left);
        }
    }
};