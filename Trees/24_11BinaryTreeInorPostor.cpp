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
public:
    
    
    TreeNode* BuildTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int poStart,int poEnd,unordered_map<int,int> &um){
        
        // base case
        if(inStart>inEnd ||poStart>poEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[poStart]);
        
        int inRoot = um[root->val];
        int rightNums = inEnd - inRoot;
        
        root->left = BuildTree(inorder,inStart,inRoot-1,postorder,poStart+rightNums+1,poEnd,um);
        
        root->right = BuildTree(inorder,inRoot+1,inEnd,postorder,poStart+1,poStart+rightNums,um);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // reverse the postorder  (root-right-left)
        reverse(postorder.begin(),postorder.end());
        // store the indexising for values
        unordered_map<int,int>um;
        
        for(int i=0;i<inorder.size();i++){
            um[inorder[i]]=i;
        }
        
        int inStart = 0;
        int inEnd = inorder.size()-1;
        
        int poStart = 0;
        int poEnd = postorder.size()-1;
        
        return BuildTree(inorder,inStart,inEnd,postorder,poStart,poEnd,um);
    }
};
