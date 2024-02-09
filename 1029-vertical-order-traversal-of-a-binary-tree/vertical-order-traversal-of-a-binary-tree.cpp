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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        // map<verInd,map<rowInd,{e1,e2,e3,e4,..}>
        map<int,map<int,multiset<int>>>um; 
        // node,ver,row
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto node = q.front();q.pop();

            int val = node.first->val;
            int ver = node.second.first;
            int row = node.second.second;

            um[ver][row].insert(val);

            if(node.first->left){
                q.push({node.first->left,{ver-1,row+1}});
            }

            if(node.first->right){
                q.push({node.first->right,{ver+1,row+1}});
            }
        }

        for(auto it:um){
            vector<int>col;
            for(auto vals:it.second){
                for(auto t:vals.second){
                    col.push_back(t);
                }               
            }
            ans.push_back(col);
        }

        return ans;        
    }
};