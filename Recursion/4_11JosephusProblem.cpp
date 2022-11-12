//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    
    void solve(int index,vector<int>&persons,int k,int &ans){
        
        // Base case
        if(persons.size()==1){
            ans = persons[0];
            return;
        }
        
        // hypothesis -> updated index
        index = (index + k)%persons.size();
        // we deleting that index
        persons.erase(persons.begin()+index);
        
        // recursive call
        solve(index,persons,k,ans);
        
        // here is no induction step becoz when we delete person permantaly
    }
    
    int josephus(int n, int k)
    {
       int ans;
       int index=0;
       vector<int>persons;
       k = k-1;
       
       for(int i=1;i<=n;i++){
           persons.push_back(i);
       }
       
       solve(index,persons,k,ans);
       return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
