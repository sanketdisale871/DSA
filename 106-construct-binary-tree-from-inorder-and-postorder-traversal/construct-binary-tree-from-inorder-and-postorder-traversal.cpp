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
    unordered_map<int,int>um; // um[i] => Tell the Index of 'i' element, where it occure in inorder

    TreeNode* buildTree(int postStart,int postEnd,vector<int>& postorder,
    int inStart,int inEnd,vector<int>& inorder){
        // Base case
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postStart]);

        int inRoot = um[root->val];
        int rightNums = inEnd-inRoot;

        root->left = buildTree(postStart+rightNums+1,postEnd,postorder,inStart,inRoot-1,inorder);

        root->right = buildTree(postStart+1,postStart+rightNums,postorder,inRoot+1,inEnd,inorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            um[inorder[i]]=i;
        }
        int n = inorder.size();

        reverse(postorder.begin(),postorder.end());

        int postStart = 0;
        int postEnd = n-1;
        int inStart = 0;
        int inEnd = n-1;

        return buildTree(postStart,postEnd,postorder,inStart,inEnd,inorder);
    }
};