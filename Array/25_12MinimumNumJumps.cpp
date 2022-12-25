//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // if the only one element in array then no need to jmp ,  we have to go end element of array
        if(n==1){
            return 0;
        }
        // if first element is zero then traversing not possible
        if(arr[0]==0){
            return -1;
        }
        
        int range = arr[0];
        int steps = arr[0];
        int JMP = 1;
        
        for(int i=1;i<n;i++){
            // if i am at last element the i traversed all array in JMPS
            if(i==n-1){
                return JMP;
            }
            
            range = max(range,i+arr[i]);
            steps--;
            
            if(steps==0){
                JMP++;
                
                if(i>=range){ // this is for 100 like elements
                    return -1;
                }
                steps = range - i;
            }
        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
