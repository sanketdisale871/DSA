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
    unordered_map<int,int>um;
    TreeNode* buildTreeIt(int inStart,int inEnd,int preStart,int preEnd,vector<int>&preorder,
    vector<int>&inorder){
        // Base case
        if(inStart>inEnd || preStart>preEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = um[preorder[preStart]];
        int lefNums = inRoot-inStart;

        root->left = buildTreeIt(inStart,inRoot-1,preStart+1,preStart+lefNums,preorder,inorder);
        root->right = buildTreeIt(inRoot+1,inEnd,preStart+lefNums+1,preEnd,preorder,inorder);

        return root;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++){
            um[inorder[i]]=i;
        }
                
        return buildTreeIt(0,inorder.size()-1,0,preorder.size()-1,preorder,inorder);
    }
};