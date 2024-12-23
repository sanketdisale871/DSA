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
    int minimumOperations(TreeNode* root) {
        int oper = 0;
        queue<TreeNode*>q;
        q.push(root);


        while(!q.empty()){
            int siz = q.size();

            vector<int>vals;


            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();

                vals.push_back(it->val);

                if(it->left){
                    q.push(it->left);
                }

                if(it->right){
                    q.push(it->right);
                }
            }

            vector<int>temp = vals;

            sort(temp.begin(),temp.end());

            unordered_map<int,int>um;

            for(int i=0;i<vals.size();i++){
                um[vals[i]]=i;
            }

           for(int i=0;i<temp.size();i++){
                if(temp[i]!=vals[i]){
                    int cur = um[temp[i]];
                    um[vals[i]]=cur;

                    swap(vals[i],vals[cur]);
                    oper++;
                }
           }
        }
        return oper;
    }
};