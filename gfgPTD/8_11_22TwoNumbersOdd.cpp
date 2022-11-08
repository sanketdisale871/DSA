//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long int x = 0;
        
        for(int i=0;i<n;i++){
            x=x^arr[i];
        }
        
        long long int f = 0;
        long long int s = 0;
        
        int set = x & ~(x-1) ;
        
        for(int i=0;i<n;i++){
            
            if(arr[i] & set){
                f = f^arr[i];
            }else{
                s = s^arr[i];
            }
        }
        
        if(f>s){
            return {f,s};
        }else{
            return {s,f};
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
