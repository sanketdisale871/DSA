//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{  
    //DSA Student : Sanket Disale
    
    /* Approach :
        i) Our search space is from constraints.
        ii) And choose one number,and check this number is meadian or not.
            a) Find the number less than number than this, in row
            b) 
    
    */
public:
    int countSmallerThanMid(int mid,vector<int>&arr){
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high){
            int md = (low+high)>>1;
            
            if(arr[md]<=mid){
                low = md+1;
            }
            else{
                high = md-1;
            }
        }
        return low; // point the index that just greater than given number
    }

    int median(vector<vector<int>> &matrix, int m, int n){
        int low = 1; // It's given in constraits
        int high = 2000; 
        
        while(low<=high){
            int mid = (low+high)>>1;
            
            int cnt = 0;
            
            for(int i=0;i<m;i++){
                cnt+=countSmallerThanMid(mid,matrix[i]);
            }
            if(cnt<=(m*n)/2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low; // 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
