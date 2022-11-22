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
    
    vector<int>ans;
    
    void postOrder(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        // PostOrder : left -right - root
        postOrder(root->left);
        postOrder(root->right);
        
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        /* Recursive approach*/
        // postOrder(root);
        
        /* Iterative Approach */
        
        stack<TreeNode*>st1;
        stack<int>st2;
        
        if(root==NULL){
            return ans;
        }
        
        st1.push(root);
        
        while(!st1.empty()){
            
            TreeNode* node = st1.top();
            st1.pop();
            
            st2.push(node->val);
            
            if(node->left){
                st1.push(node->left);
            }
            
            if(node->right){
                st1.push(node->right);
            }
            
        }
        
        while(!st2.empty()){
            int elem = st2.top();
            st2.pop();            
            ans.push_back(elem);
        }
        
        return ans;
            
            
    }
};
