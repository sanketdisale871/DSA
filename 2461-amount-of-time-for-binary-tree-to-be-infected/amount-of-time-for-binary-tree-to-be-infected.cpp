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
    /*
    Approach: 1) I will create the Graph from tree
    2) Calculate the Time from StartNode, which one is maximum time that i have
    */
    unordered_map<int,vector<int>>um;

    void createGraph(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto it = q.front();q.pop();

            if(it->left){
                int u = it->val;
                int v = it->left->val;

                um[u].push_back(v);
                um[v].push_back(u);

                q.push(it->left);
            }

            if(it->right){
                int u = it->val;
                int v = it->right->val;

                um[u].push_back(v);
                um[v].push_back(u);

                q.push(it->right);
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);

        int time = 0;
        unordered_set<int>vis;
        queue<pair<int,int>>q;
        q.push({0,start});
        vis.insert(start);

        while(!q.empty()){
            auto it = q.front();q.pop();

            int t = it.first;
            int node = it.second;

            time = max(t,time);

            for(auto it:um[node]){
                if(vis.count(it)==0){
                    q.push({t+1,it});
                    vis.insert(it);
                }
            }
        }
        return time;
    }
};