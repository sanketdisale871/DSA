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

    int prevNum = INT_MIN,currFreq = 0,maxFreq = 0;

    void traverseTree(TreeNode* root, vector<int>&ans){
        // base case
        if(root == NULL){
            return ;
        }

        traverseTree(root->left,ans);

        if(prevNum == root->val){
            currFreq++;
        }
        else{
            currFreq = 1;
            prevNum = root->val;
        }

        if(currFreq > maxFreq){
            ans.clear();
            maxFreq = currFreq;
            ans.push_back(root->val);
        }
        else if(currFreq == maxFreq){
            ans.push_back(root->val);
        }

        traverseTree(root->right,ans);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        traverseTree(root,ans);

        return ans;
    }
};