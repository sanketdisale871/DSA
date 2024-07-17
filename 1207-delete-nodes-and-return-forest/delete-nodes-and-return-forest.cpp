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
    vector<TreeNode*>ans;
    unordered_set<int>st;

    void traversal(TreeNode* &root){
        if(root == NULL){
            return ;
        }

        traversal(root->left);
        traversal(root->right);

        if(st.count(root->val)!=0){ // Ab mai current node ko delete kar raha, to Root ke left ka and root ke right ke nye do root node ho gaye.
           
            if(root->left){ 
                ans.push_back(root->left);
            }

            if(root->right){
                ans.push_back(root->right);
            }

            root = NULL;
            delete root;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto it:to_delete){
            st.insert(it);
        }

        traversal(root);

        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};