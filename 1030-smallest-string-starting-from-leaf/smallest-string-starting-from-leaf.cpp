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
    string ans = "-1";

    void doTraversal(TreeNode* root,string str){
        if(root==NULL){
            return ;
        }
        str.push_back(root->val+'a');
        if(root->left == NULL && root->right==NULL){
            // string temp = str;
            reverse(str.begin(),str.end());

            if(ans=="-1"){
                ans = str;
            }
            else{
                ans = min(ans,str);
            }
            return ;
        }

        doTraversal(root->left,str);
        doTraversal(root->right,str);

    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string str = "";

        doTraversal(root,str);

        return ans;
    }
};