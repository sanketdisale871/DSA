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
    int ans = 0;

    int sum(TreeNode* root,int &cnt){
        // Base case
        if(root == NULL){
            return 0;
        }
        cnt++;
        int left = sum(root->left,cnt);
        int right = sum(root->right,cnt);

        return root->val + left + right;
    }

    void solve(TreeNode* root){
        // Base case
        if(root == NULL){
            return;
        }

        int cnt = 0;
        int avg = sum(root,cnt)/cnt;
        if(avg == root->val){
            ans++;
        }

        solve(root->left);
        solve(root->right);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};