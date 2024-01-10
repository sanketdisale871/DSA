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
    unordered_map<int,vector<int>>v; // Adjacancy List 

    void createrGraph(TreeNode* root){
        queue<pair<TreeNode*,int>>q; // pair<TreeNode,parent>
        q.push({root,-1});

        while(!q.empty()){
            auto it = q.front();q.pop();
            auto node = it.first;
            int par = it.second;

            if(par!=-1){
                v[par].push_back(node->val);
                v[node->val].push_back(par);
            }

            if(node->left){
                q.push({node->left,node->val});
            }
            if(node->right){
                q.push({node->right,node->val});
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        createrGraph(root);

        int t = 0;

        unordered_map<int,bool>vis;
        queue<pair<int,int>>q;
        q.push({start,0});
        vis[start]=true;

        while(!q.empty()){
            auto it = q.front();q.pop();
            int node = it.first;
            int cost = it.second;

            t=max(t,cost);

            for(auto it:v[node]){
                if(!vis[it]){
                    q.push({it,cost+1});
                    vis[it]=true;
                }
            }
        }
        return t;
    }
};