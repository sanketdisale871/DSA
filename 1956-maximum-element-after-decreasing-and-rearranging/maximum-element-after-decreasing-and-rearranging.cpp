class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int ans = 1;
        arr[0]=1;

        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];

            if(diff>1){
                arr[i]=1+arr[i-1];
            }
            ans = max(ans,arr[i]);
        }
        return ans;

        
    }
};