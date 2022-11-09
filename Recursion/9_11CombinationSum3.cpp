//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
  vector<vector<int>>ans;

  
  void solve(int index,vector<int>&arr,int target,int n,vector<int>&temp){
      
      // base case : JB puray array traversal ho jaye to return kardo
      if(index==n){
          if(target == 0){ // jb target zero ho jaye to ans o vector daldo 
              ans.push_back(temp);
          }
          return;
      }
      
      // first call for pick up the index , incoming element must be less than or equal to target
      if(arr[index]<=target){
          temp.push_back(arr[index]);
          
          solve(index,arr,target-arr[index],n,temp);
          
        // backtrakking
          temp.pop_back();
      }
      
      // second call for non pick up the index
      
      solve(index+1,arr,target,n,temp);
  }
  
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &given, int B) {
        // becoz of repeatabel numbers , i use map to store the distinict numbers
    unordered_map<int,int>mp;
    
    for(int i=0;i<given.size();i++){
        mp[given[i]]++;
    }
    // this is the array contain disinict numbers
    vector<int>arr;
    
    for(auto &it : mp){
        arr.push_back(it.first);
    }
    
    sort(arr.begin(),arr.end());
     
     vector<int>temp;
     
    solve(0,arr,B,arr.size(),temp);   
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends
