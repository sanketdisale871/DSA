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

    void traverseTree(TreeNode* root, unordered_map<int,int> &um,int &maxOccur){
        // base case
        if(root == NULL){
            return ;
        }

        traverseTree(root->left,um,maxOccur);

        um[root->val]++;
        maxOccur = max(maxOccur,um[root->val]);

        traverseTree(root->right,um,maxOccur);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>um;
        int maxOccur = 1;

        traverseTree(root,um,maxOccur);

        for(auto it : um){
            if(it.second == maxOccur){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};