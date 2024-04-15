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
    typedef long long int ll;

    ll sum = 0;

    void trav(TreeNode* root, ll num){
        if(root == NULL){
            return ;
        }

        num = num*10 + root->val;

        if(root->left ==NULL && root->right == NULL){
            sum+=num;
            return ;
        }

        trav(root->left,num);
        trav(root->right,num);
    }

public:
    int sumNumbers(TreeNode* root) {
        ll num = 0;

        trav(root,num);

        return (int)sum;
    }
};