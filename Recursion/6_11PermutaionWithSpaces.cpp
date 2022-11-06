//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
public:
vector<string>ans;

    void solve(int index,string &op,string &s,int n){
        
        // base case
        if(index==n){
            ans.push_back(op);
            return;
        }
        
        //space lena hai 
        if(index>0){
            op.push_back(' ');
            op.push_back(s[index]);
            
            // recursive call
            solve(index+1,op,s,n);
            op.pop_back();
            op.pop_back();
        }
        
        // space nahi lena hai
        
        op.push_back(s[index]);
         solve(index+1,op,s,n);
         // backtraking
         op.pop_back();
        
    }

    vector<string> permutation(string s){
        
        int index = 0;
        string op = "";
        
        solve(index,op,s,s.length());
    
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends
