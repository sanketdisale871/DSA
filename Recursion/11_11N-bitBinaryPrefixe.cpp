//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    vector<string>ans;
    
    void solve(string &temp,int one,int zero,int n){
        
        // Base condition - leaf node
        if(n==0){
            ans.push_back(temp);
            return;
        }
        
        // one choice available in tree
        temp+='1';
        solve(temp,one+1,zero,n-1);
        temp.pop_back();
        
        // zero choice available only if one > zero
        if(one>zero){
            temp+='0';
            solve(temp,one,zero+1,n-1);
            temp.pop_back();
        }
    }
    

	vector<string> NBitBinary(int N)
	{   
	    string temp= "";
	    int one = 0;
	    int two = 0;
	    
	    solve(temp,one,two,N);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
