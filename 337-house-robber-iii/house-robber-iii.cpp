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
    // pair<takenThisOne,withouTakenThisOne>
    pair<ll,ll>findMaxiPro(TreeNode* root){
        // base case
        if(root==NULL){
            return {0,0};
        }

        auto lef =findMaxiPro(root->left);
        auto rig =findMaxiPro(root->right);

        pair<ll,ll>res;
        res.first = root->val + lef.second + rig.second;
        res.second = max(lef.first,lef.second)+max(rig.first,rig.second);

        return res;
    }
public:
    int rob(TreeNode* root) {
        auto r = findMaxiPro(root);

        return (int) max(r.first,r.second);
    }
};