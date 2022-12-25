//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    
    void reverseArray(vector<long long>&arr,int i,int j){
        
        // base case
        if(i>=j){
            return;
        }
        swap(arr[i],arr[j]);
        
        reverseArray(arr,i+1,j-1);
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
       
       int N = n-1;
       k = k-1;
      int s = 0;
      int e = k;
      
      while(e<=N){
          reverseArray(arr,s,e);
          s = e+1;
          e = s+k;
      }
      
      if(e-N > 0){
          reverseArray(arr,s,N);      }
         
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
