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
    typedef long long int ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        
        // pair<TreeNode*,ind> q
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});

        while(!q.empty()){
            int siz = q.size();

            ll stInd=0;
            ll endInd=0;
            

            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();
                TreeNode* node = it.first;

                if(i==0){
                    stInd = it.second;
                }

                ll ind = it.second-stInd;

            
                if(i==siz-1){
                    endInd = it.second;
                }

                if(node->left){
                    q.push({node->left,(2*ind)+1});
                }

                if(node->right){
                    q.push({node->right,(2*ind)+2});
                }
            }

            ll res = endInd-stInd+1;
            ans = max(ans,res);
        }
        return ans;
    }
};