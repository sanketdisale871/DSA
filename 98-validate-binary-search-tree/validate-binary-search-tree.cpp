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
    // int prevNum = INT_MIN;
    bool isBST = true; 


//     Root Val : 1 MiniBound : 0 MaxiBoudn 2
// Root Val : 2 MiniBound : 0 MaxiBoudn -1
// Root Val : 3 MiniBound : 2 MaxiBoudn -1

    void checkBST(TreeNode* root,long long minBound,long long maxiBound)
    {
        if(root==nullptr)
        {
            return;
        }

        checkBST(root->left,minBound,root->val);

        cout<<"Root Val : "<<root->val<<" MiniBound : "<<minBound<<" MaxiBoudn "<<maxiBound<<endl;
        if(root->val<=minBound || root->val >= maxiBound){
            isBST = false;
        }
     
        checkBST(root->right,root->val,maxiBound);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
       
       checkBST(root, LLONG_MIN, LLONG_MAX); 
       
        return isBST;
    }
    /*
    T.C:  O(N)
    S.C: O(1)
    
    */
};