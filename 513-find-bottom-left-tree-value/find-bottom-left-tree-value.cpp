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
    
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int siz = q.size();

            for(int i=0;i<siz;i++){
                auto node = q.front();q.pop();

                if(i==0){
                    ans = node->val;
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