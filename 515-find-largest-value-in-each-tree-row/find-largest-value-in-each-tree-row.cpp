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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;

        if(root ==NULL){
            return{};
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int siz = q.size();
            int maxElem = INT_MIN;
            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();

                maxElem = max(maxElem,it->val);

                if(it->left){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }

            }
            ans.push_back(maxElem);
        }
        return ans;
    }
};