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
    // First time : Comes in my Mind 
    // int findMaxiPath(TreeNode* root,int &maxi){
    //     // Base case
    //     if(root==NULL){
    //         return 0;
    //     }

    //     int lefPa = findMaxiPath(root->left,maxi);
    //     int rigPa = findMaxiPath(root->right,maxi);

    //     int res = lefPa + rigPa + root->val;
    //     maxi = max(maxi,res); // By considering node + leftPath  + rightPath
    //     maxi = max(maxi,root->val); //  By considering only node
    //     maxi = max(maxi,root->val+lefPa);//  By considering node + leftPath
    //     maxi = max(maxi,root->val+rigPa); // By Considering node + rightPath

    //     return max(root->val+max(lefPa,rigPa),root->val); // Returning a singleNode, aur left/right maximum wala node from currentNode se..
    // }

    int findMaxiPath1(TreeNode*root,int &maxi){
        // Base case
        if(root==NULL){
            return 0;
        }

        int lefPath = max(0,findMaxiPath1(root->left,maxi)); // Hamesha negative wali aur negative bana degi
        int riPath = max(0,findMaxiPath1(root->right,maxi));

        int res = root->val + lefPath + riPath;
        maxi = max(maxi,res);

        return root->val+max(lefPath,riPath);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        findMaxiPath1(root,maxi);

        return maxi;
    }
};