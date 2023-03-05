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
    /* DSA Student : Sanket Disale */
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        
        if(root == NULL){
            return -1;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
                
                sum=sum+1LL*node->val;
            }
            pq.push(sum);
        }
        
        if(pq.size()<k){
            return -1;
        }
        k--;
        
        while(k--){
            pq.pop();
        }
        
        return pq.top();
            
    
        
    }
};
