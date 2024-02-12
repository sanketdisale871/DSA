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



    void traverse(TreeNode* root,TreeNode*target,int k,int dist){
        // base case
        if(root == NULL){
            return ;
        }

        if(dist==k && root->val!=target->val){
            ans.push_back(root->val);
            return;
        }

        if(dist>k){
            return;
        }

        if(root->left && nodes.count(root->left->val)>0){
            nodes.erase(root->left->val);
            traverse(root->left,target,k,dist+1);
        }

        if(root->right && nodes.count(root->right->val)>0){
            nodes.erase(root->right->val);
            traverse(root->right,target,k,dist+1);
        }

        if(um.find(root)!=um.end() && nodes.count(um[root]->val)>0){
            nodes.erase(um[root]->val);
            traverse(um[root],target,k,dist+1);
        }

    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(k==0){
            return {target->val};
        }
        
        parentMappind(root);

        nodes.erase(target->val);
        traverse(target,target,k,0);

        return ans;
    }
};