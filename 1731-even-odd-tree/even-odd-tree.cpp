/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };fd
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        /*
        Understanding : 
        1) i will keep the track of level,and nodes of that level
        ii) if whole tree satisfied the condition then tree is sat        
        */

        queue<TreeNode*>q;
        q.push(root);

        int lvl = 0;

        while(!q.empty()){
            int siz = q.size();
            int prev;

            if(lvl%2==0){
                prev = 0;
            }
            else{
                prev = INT_MAX;
            }

            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();

                int nodeVal = it->val;

                if(lvl%2==0 && (nodeVal%2==0)){
                    return false;
                }

                if(lvl%2!=0 && (nodeVal%2!=0)){
                    return false;
                }

                if( lvl%2==0 && nodeVal<=prev){
                    return false;
                }

                if(lvl%2!=0 && nodeVal>=prev){
                    return false;
                }

                prev = nodeVal;

                if(it->left){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }
            }
            lvl++;
        }

        return true;
    }
};