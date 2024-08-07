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

    TreeNode* builtTree(int inStart,int inEnd,vector<int>&inOrd,int preStart,int preEnd,vector<int>&preOrd){
        if(inStart>inEnd || preStart>preEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preOrd[preStart]);
        int inRoot = um[preOrd[preStart]];
        int lefElem = inRoot-inStart;

        root->left = builtTree(inStart,inRoot-1,inOrd,preStart+1,preStart+lefElem,preOrd);
        root->right = builtTree(inRoot+1,inEnd,inOrd,preStart+lefElem+1,preEnd,preOrd);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preOrd, vector<int>& inOrd) {
        for(int i=0;i<inOrd.size();i++){
            um[inOrd[i]]=i;
        }

        int inStart = 0,inEnd = inOrd.size()-1;
        int preStart =0,preEnd = preOrd.size()-1;

        return builtTree(inStart,inEnd,inOrd,preStart,preEnd,preOrd);
    }
};