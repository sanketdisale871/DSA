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
    TreeNode* buildTree(vector<int>&nums,int l,int h){
        if(l>h){
            return NULL;
        }

        int mid = l + (h-l)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = buildTree(nums,l,mid-1);
        newNode->right = buildTree(nums,mid+1,h);

        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0,h = nums.size()-1;

        return buildTree(nums,l,h);
    }
};