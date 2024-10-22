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
    typedef long long int ll;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>minHeap;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            ll siz = q.size();

            ll s = 0;

            for(ll i=0;i<siz;i++){
                auto node = q.front();
                q.pop();

                s+=node->val;

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            minHeap.push(s);

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        if(minHeap.size()<k){
            return -1;
        }
        return minHeap.top();
    }
};