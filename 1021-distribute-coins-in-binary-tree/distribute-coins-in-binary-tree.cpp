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
    int findTotalCount(TreeNode* root,int &moves){
         if(root==NULL){
            return 0;
        }

        if(root && root->left == NULL && root->right == NULL){
            return 1-root->val;
            /*
            Value +x = This node want x coin (It's 1 at most)
            -x = This node have x extra coins
            */
        }

        int leftCost = 0,rightCost = 0;

        if(root->left){
            leftCost = findTotalCount(root->left,moves);
        } 

        if(root->right){
            rightCost = findTotalCount(root->right,moves);
        }

        moves+= abs(leftCost) + abs(rightCost);

        int totalCost = leftCost + rightCost + (1-root->val);

        return totalCost;
    }
public:
    int distributeCoins(TreeNode* root) {
       int moves = 0;

        findTotalCount(root,moves);

        return moves;
    }
};