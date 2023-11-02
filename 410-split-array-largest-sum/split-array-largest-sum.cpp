class Solution {
    private:
    bool isPossible(long long mid,vector<int>& nums, int k){
        int split = 1;

        long long sum = 0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(sum>mid){
                split++;
                sum = nums[i];
            }
        }
        return split<=k;
        
    }

public:
    #define ll long long
    int splitArray(vector<int>& nums, int k) {
        ll low = *max_element(nums.begin(),nums.end());
        ll high = accumulate(nums.begin(),nums.end(),0);

        int ans = -1;
        while(low<=high){
            ll mid = low + (high-low)/2;

            if(isPossible(mid,nums,k)){
                ans = (int)mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};