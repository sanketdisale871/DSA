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
    int findMaxiPath(TreeNode* root,int &maxi){
        // Base case
        if(root==NULL){
            return 0;
        }

        int lefPa = findMaxiPath(root->left,maxi);
        int rigPa = findMaxiPath(root->right,maxi);

        int res = lefPa + rigPa + root->val;
        maxi = max(maxi,res);
        maxi = max(maxi,root->val);
        maxi = max(maxi,root->val+lefPa);
        maxi = max(maxi,root->val+rigPa);

        return max(root->val+max(lefPa,rigPa),root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findMaxiPath(root,maxi);

        return maxi;
    }
};