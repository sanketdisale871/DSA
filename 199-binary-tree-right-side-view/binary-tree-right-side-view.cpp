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
    vector<int> rightSideView(TreeNode* root) {
       vector<int>ans;

        // Edge Case -> How many Nodes are given this determine
       if(root==NULL){
           return ans;
       }

       queue<TreeNode*>q;
       q.push(root);

       while(!q.empty()){
           int siz = q.size();

           for(int i=0;i<siz;i++){
               auto node = q.front();q.pop();

               if(i==siz-1){
                  ans.push_back(node->val); 
               }
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
           }
       }

       return ans;
    }
};