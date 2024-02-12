/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // By using level wise traversal => I will make it TreeTraversal
        queue<TreeNode*>q;
        q.push(root);

        string str = "";

        while(!q.empty()){
            auto it = q.front();q.pop();

            if(it==NULL){
                str.append("#,");
            }
            else{
                str.append(to_string(it->val)+',');
            }

            if(it!=NULL){
                q.push(it->left);
                q.push(it->right);
            }
        }

        cout<<"String : "<<str<<endl;

        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n = data.length();

        if(data[0]=='#'){
            return NULL;
        }

        stringstream s(data);
        string str;

        getline(s,str,',');

        TreeNode*root = new TreeNode(stoi(str));

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            auto node = q.front();q.pop();


            // Left Wala banda dhundate hai
            getline(s,str,',');

            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                node->left = newNode;
                q.push(newNode);
            }

            // Right wala banda dhundate hai
            
            getline(s,str,',');

            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode* newNode = new TreeNode(stoi(str));
                node->right = newNode;
                q.push(newNode);
            }

        }       

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));