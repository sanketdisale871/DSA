//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    // DSA Student : Sanket Disale
    public:
 /*Algortithm : 
 1) Push the all persons into the stack.
 2) Check which dont know other persons bt all knows him
 3) Up to that stack will contain one element
 4) For confirmation, check it's row and cols
 */
    int celebrity(vector<vector<int> >& matrix, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            int a =st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(matrix[a][b]==1){ // a knows the b,b may be celebrity
                st.push(b);
            }
            else if(matrix[b][a]==1){ // b knows a , a may be celebrity
                st.push(a);
            }
        }
        int potCele = st.top(); // It may be celebrity, for confirmation we are checking it's row and columns
        
        int oneCnt = 0;
        int zeroCnt = 0;
        // check row and column
        for(int i=0;i<n;i++){
            if(matrix[i][potCele]==1){
                oneCnt++;
            }
            
            if(matrix[potCele][i]==0){
                zeroCnt++;
            }
            
        }
        if(oneCnt!=(n-1) || zeroCnt!=n){
            return -1;
        }
        return potCele;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
