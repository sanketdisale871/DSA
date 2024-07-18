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
    int ans = 0;
public:

    vector<int> dfsTrav(TreeNode* root,int dist){
        vector<int>p ={};

        if(root==NULL){
            return p;
        }

        auto lef = dfsTrav(root->left,dist);
        auto righ = dfsTrav(root->right,dist);

        if(lef.size()==0 && righ.size()==0){ // Leaf node
                p.push_back(1);
                return p;
        }

        // pairs calculating 
        for(int i=0;i<lef.size();i++){
            for(int j=0;j<righ.size();j++){
                if(lef[i]+righ[j]<=dist){
                    ans++;
                }
            }
        }

        for(int i=0;i<lef.size();i++){
            lef[i]++;
            p.push_back(lef[i]);
        }

        for(int i=0;i<righ.size();i++){
            righ[i]++;
            p.push_back(righ[i]);
        }

        return p;

    }

    int countPairs(TreeNode* root, int dist) {
        dfsTrav(root,dist);

        return ans;
    }
};