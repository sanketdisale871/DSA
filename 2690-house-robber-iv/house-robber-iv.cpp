class Solution {
    private:
    bool isPossible(int mid,vector<int>&nums,int k){
        int houseRobbed = 0;  
        int i=0;

        while(i<nums.size()){
            if(nums[i]<=mid){
                houseRobbed++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return houseRobbed>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        int ans=-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};