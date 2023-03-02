//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Approach 2 : Two Pointer Approach
    /*
    T.C. : O(n)
    S.C. : O(1)
    
    */
    public:
    long long trappingWater(int arr[], int n){
        long long res = 0;
        long long leftMax = 0;
        long long rightMax = 0;
        int l = 0;
        int r = n-1;
        while(l<r){
            
     if(arr[l]<=arr[r]){
            if(arr[l]>=leftMax){
                leftMax = arr[l];
            }
            else{
                res+=(leftMax - arr[l]);
            }
            l++;
        }
    else{
        if(arr[r]>=rightMax){
            rightMax = arr[r];
        }
        else{
            res+=(rightMax - arr[r]);
        }
        r--;
    }    
            
        }
        return res;
        

    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
