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
    // pair.first => withRobber,,, pair.Second => withoutRobbery
    pair<int,int>findMaxiRobery(TreeNode* root){

        // base case 
        if(root == NULL){
            return {0,0};
        }

        auto leftRob = findMaxiRobery(root->left);
        auto rigRob = findMaxiRobery(root->right);

        pair<int,int>currRob;

        currRob.first = root->val + leftRob.second+rigRob.second;
        currRob.second = max(leftRob.first,leftRob.second)+max(rigRob.first,rigRob.second);

        return currRob;
    }
public:
    int rob(TreeNode* root) {
        auto res = findMaxiRobery(root);

        return max(res.first,res.second);
    }
};