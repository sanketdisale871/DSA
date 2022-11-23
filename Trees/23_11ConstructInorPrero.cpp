//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    
    Node* buildTreeRecur(int pre[],int preStart,int preEnd,int in[],int inStart,int inEnd,unordered_map<int,int>&um){
        
        
        // base case
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        
        // create new root element with preorder value
        Node* root = new Node(pre[preStart]);
        
        int inRoot = um[root->data];
        int leftNums = inRoot - inStart;
        
        root->left = buildTreeRecur(pre,preStart+1,preStart+leftNums,in,inStart,inRoot-1,um);
        root->right =buildTreeRecur(pre,preStart+leftNums+1,preEnd,in,inRoot+1,inEnd,um);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
       
       unordered_map<int,int>um;
       
       for(int i=0;i<n;i++){
           um[in[i]]=i;
       }
       
       int inStart = 0;
       int inEnd = n-1;
       
       int preStart = 0;
       int preEnd = n-1;
       
       return buildTreeRecur(pre,preStart,preEnd,in,inStart,inEnd,um);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
