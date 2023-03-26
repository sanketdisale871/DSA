//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // DSA Student :  Sanket Disale !
    public:
    long long sumBetweenTwoKth( long long arr[], long long n, long long k1, long long k2)
    {
        /* Approach 1 : T.C. 2 * (n (log n))
        i) Declare the Kth Smallest number finding function
        ii) call that function for k1 and k2 and store the respctive answers in first and second
        ii) And then , Add the all elements in between of first and second
        */
        
        /* Approach 2 : T.C. : O(n * long(n))
        i)  find the max(k1,k2) the smallest numbers and store into the 'second'
        ii) find the min(k1,k2) the smallest number and store into the 'first'
        iii) and add the numbers in between first and second
        */
        
        priority_queue<int>maxHeap;
        long long ans = 0;
        long long first,second;
        
        for(int i=0;i<n;i++){
            maxHeap.push(arr[i]);
            
            if(maxHeap.size()> max(k1,k2)){
                maxHeap.pop();
            }
        }
        second = maxHeap.top();
        
        while(maxHeap.size()>min(k1,k2)){
            maxHeap.pop();
        }
        first = maxHeap.top();
        
        for(int i=0;i<n;i++){
            if(arr[i]>first and arr[i]<second){
                ans+=arr[i];
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
