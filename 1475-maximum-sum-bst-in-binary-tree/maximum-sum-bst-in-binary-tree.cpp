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

class NodeValues{
    public:
    int maxVal;
    int minVal;
    int maxSum;

    NodeValues(int miniVal,int maxiVal,int maxiSum){
        minVal = miniVal;
        maxVal = maxiVal;
        maxSum = maxiSum;
    }  
};

class Solution {
    private:
    int sum = -1;
    NodeValues* findMaxSum(TreeNode* root){
        if(root == NULL){
            return new NodeValues(INT_MAX,INT_MIN,0);
        }

        auto lef = findMaxSum(root->left);
        auto righ = findMaxSum(root->right);

        if(lef->maxVal < root->val && root->val < righ->minVal){
            sum = max(sum,lef->maxSum + righ->maxSum + root->val);
            return new NodeValues(min(root->val,lef->minVal),max(root->val,righ->maxVal),lef->maxSum + righ->maxSum + root->val);
        }
        else{
            return new NodeValues(INT_MIN,INT_MAX,max({0,lef->maxSum,righ->maxSum}));
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        auto it = findMaxSum(root);


        return sum<0?0:sum;
    }
};