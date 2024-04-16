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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // edge case 
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        queue<TreeNode*>q;

        q.push(root);

        int currDep = 2;

        while(!q.empty() && currDep<depth){
            int siz = q.size();

            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();

                if(it->left){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }
            }
            currDep++;
        }

        while(!q.empty()){
            auto it = q.front();q.pop();

            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            
            node1->left = it->left;
            node2->right = it->right;

            it->left = node1;
            it->right = node2;
        }

        return root;

    }
};