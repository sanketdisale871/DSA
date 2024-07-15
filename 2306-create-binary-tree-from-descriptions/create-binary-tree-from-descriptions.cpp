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

public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>um;
        unordered_map<int,int>paretTrack;
        int value;
        for(auto it:desc){
            int par = it[0];
            int chil = it[1];
            int isLef = it[2];

            TreeNode* parent;
            TreeNode* child;

            if(um.find(par)!= um.end()){
                parent = um[par];
            }
            else{
                um[par]= new TreeNode(par);
                parent = um[par];
            }

            if(um.find(chil) != um.end()){
                child = um[chil];
            }
            else{
                um[chil]= new TreeNode(chil);
                child = um[chil];
            }


            if(isLef){
                parent->left = child;
                paretTrack[child->val]=parent->val;
                value = child->val;
            }
            else{
                parent->right = child;
                paretTrack[child->val]=parent->val;
                value = child->val;
            }
        }

        TreeNode* root;

        while(paretTrack[value]!=0){
            value = paretTrack[value];
        }
        root = um[value];

        return root;
    }
};