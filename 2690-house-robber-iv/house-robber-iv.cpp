class Solution {
    private:
    bool isPossible(vector<int>&nums,int maxAmnt,int k){
        int i=0;
        int n = nums.size();
        int house = 0;

        while(i<n){
            if(nums[i]<=maxAmnt){
                house++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return house>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isPossible(nums,mid,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;
    }
};