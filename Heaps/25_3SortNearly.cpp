//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ // DSA Student : Sanket Disale
    public:
    /*Approcah : 
      Each element is at most distance 'k' form target Position. Therefore, the 
      Min Heap will contain minimum element upto [i-k,i+k]
    */
 
    vector <int> nearlySorted(int arr[], int n, int k){
        vector<int>ans;
        
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        for(int i=0;i<n;i++){
            minHeap.push(arr[i]);
            
            if(minHeap.size()>k){
                ans.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends
