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

class BSTIterator{
    public:
    stack<TreeNode*>st;
    bool isReversed;

    BSTIterator(TreeNode* root, bool isReverse){
        isReversed = isReverse;
        pushAll(root);
    }

    int next(){
        auto node = st.top();st.pop();

        if(isReversed){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }

        return node->val;
    }

    void pushAll(TreeNode* root){

        while(root){
            st.push(root);
            cout<<" Root : "<<root->val<<endl;

            if(isReversed){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }

    }

};

class Solution {
    
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bt1(root,false);

        BSTIterator bt2(root,true);

        int i = bt1.next();
        int j = bt2.next();

            // cout<<"i : "<<i<<" j : "<<j<<endl;
            // cout<<"bt1 Size : "<<bt1.st.size()<<" bt2 : "<<bt2.st.size();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i = bt1.next();
            }
            else{
                j = bt2.next();
            }
        }
        return false;
    }
};