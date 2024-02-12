/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:

    vector<int>ans;
    unordered_set<int>nodes;
    unordered_map<TreeNode*,TreeNode*>um;

    void parentMappind(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto it = q.front();q.pop();
            nodes.insert(it->val);

            if(it->left){
                q.push(it->left);
                um[it->left]=it;
            }

            if(it->right){
                q.push(it->right);
                um[it->right]=it;
            }
        }
    }



    void traverse(TreeNode* root,int k,int dist){
        
        if(dist==k){
            ans.push_back(root->val);
            return;
        }

        if(dist>k){
            return;
        }

        if(root->left && nodes.count(root->left->val)>0){ //Left Node present hai, and non Visited hai to jao udhar
            nodes.erase(root->left->val);
            traverse(root->left,k,dist+1);
        }

        if(root->right && nodes.count(root->right->val)>0){ //Right Node present hai, and non Visited hai to jao udhar
            nodes.erase(root->right->val);
            traverse(root->right,k,dist+1);
        }

        if(um.find(root)!=um.end() && nodes.count(um[root]->val)>0){ // Parent Node present hai, and non Visited hai to jao udhar
            nodes.erase(um[root]->val);
            traverse(um[root],k,dist+1);
        }

    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // if(k==0){
        //     return {target->val};
        // }

        parentMappind(root);

        nodes.erase(target->val);
        traverse(target,k,0);

        return ans;
    }
};