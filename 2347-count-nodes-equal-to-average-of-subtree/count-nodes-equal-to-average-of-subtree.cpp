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

    // pair<sum,cnt> 

    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        // Base case
        if(root == NULL){
            return {0,0};
        }

        auto left = solve(root->left);
        int leftSum = left.first;
        int leftCnt = left.second;

        auto right = solve(root->right);
        int rightSum = right.first;
        int rightCnt = right.second;

        int sum = leftSum + rightSum + root->val;
        int cnt = leftCnt + rightCnt + 1;

        if(root->val == (sum/cnt)){
            ans++;
        }

        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;

        solve(root);

        return ans;  
    }
};