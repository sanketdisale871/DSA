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
    int miniValue;
    int maxValue;
    int maxSum;

    NodeValues(int miniValue,int maxValue,int maxSum){
        this->miniValue = miniValue;
        this->maxValue = maxValue;
        this->maxSum = maxSum;
    }
};


class Solution {
public:
      int sum =0;
    NodeValues findSumBST(TreeNode* root){
        // base case
        if(root == NULL){
            return NodeValues(INT_MAX,INT_MIN,0);
        }

        auto left = findSumBST(root->left);
        auto right = findSumBST(root->right);

        int rootVal = root->val;
        if(left.maxValue < rootVal && rootVal < right.miniValue ){
            // IT's BST
            sum = max(sum,rootVal+left.maxSum+right.maxSum);

            return NodeValues(min(rootVal,left.miniValue),max(rootVal,right.maxValue),rootVal+left.maxSum+right.maxSum);
        }
        else{
            return NodeValues(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
        }
    }

  
    int maxSumBST(TreeNode* root) {
        findSumBST(root);

        return sum>-1 ?sum : 0;
    }
};