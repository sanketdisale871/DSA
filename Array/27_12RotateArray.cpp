class Solution {
public:
    void RightRotate(vector<int>& arr, int k) {
        int n = arr.size();

        if(k==0){
            return;
        }

        k = k%n;

        int d = n-k;
        // first reverse the n-k elements
        reverse(arr.begin(),arr.begin()+d);

        reverse(arr.begin()+d,arr.begin()+n);

        reverse(arr.begin(),arr.end());
    }
  
  void leftRotate(int arr[], int k, int n) 
	{ 
	    if(k==0){
	        return;
	    }
	    
	    k = k%n;
	    
	    // first reverse the given elements
	   
	       reverse(arr,arr+k);
	   
	   // second one is reverse remaining half elements
	   reverse(arr+k,arr+n);
	   
	   reverse(arr,arr+n); 
	    
	   
	} 
};
