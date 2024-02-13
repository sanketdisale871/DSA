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
    void inTra(TreeNode* root,string &m){
        if(root == NULL){
            m.append("#");
            return ;
        }

        m.append(to_string(root->val));

        inTra(root->left,m);


        inTra(root->right,m);
    }

    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            return true;
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(isLeaf(root) && isLeaf(subRoot)){
            if(root->val != subRoot->val){
                return false;
            }
            return true;
        }

        string mainTree;
        inTra(root,mainTree);
        cout<<"MainTree : "<<mainTree<<endl;


        string suTree;
        inTra(subRoot,suTree);
        cout<<"SubTree : "<<suTree<<endl;

        if(mainTree.find(suTree)!= string::npos){
            return true;
        }
        return false;


    }
};