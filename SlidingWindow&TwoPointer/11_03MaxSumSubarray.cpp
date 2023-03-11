//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    // long maximumSumSubarray(int k, vector<int> &arr , int n){
        
    //     long sum = 0;
    //     long maxSum = INT_MIN;
        
    //     for(int i=0;i<n;i++){
    //         // adding elements in the windwo
    //         sum+=arr[i];
            
    //         if(i-k>=0){ // Removing The Elements which is outside the window
    //             sum-=arr[i-k];
    //         }
            
    //         if(i>=(k-1)){ // Yaha window maintain ho rahi hai !
    //             maxSum = max(maxSum,sum);
    //         }
    //     }
    //     return maxSum;
    // }
    /* Second Approch*/
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        int i=0; // Start of Sliding Window
        int j=0; // End of Sliding Wingow
        
        long sum = 0;
        long maxSum = INT_MIN;
        
        while(j<n){
            sum+=arr[j];
            // widow size mai nahi hai
            if(j-i+1<k){ 
                j++;
            }
            else if(j-i+1==k){ // Window Size maintain hai
                maxSum = max(maxSum,sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
