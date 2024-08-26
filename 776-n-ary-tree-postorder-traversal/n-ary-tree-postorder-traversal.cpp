/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;

        if(root == NULL){
            return ans;
        }

        stack<Node*>st;
        st.push(root);

        // root - right - left

        while(!st.empty()){
            auto it = st.top();st.pop();

            for(int i=0;i<it->children.size();i++){
                st.push(it->children[i]);
            }

            ans.push_back(it->val);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};