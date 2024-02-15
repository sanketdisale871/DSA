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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        bool isZigZag = false;

        while(!q.empty()){
            int siz = q.size();
            vector<int>temp(siz);

            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();

                if(isZigZag){
                    temp[siz-i-1]=it->val;
                }
                else{
                    temp[i]=it->val;
                }

                if(it->left){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }
            }
            ans.push_back(temp);

            isZigZag=!isZigZag;            
        }
        return ans;
    }
};