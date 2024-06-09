class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        um[0]=1;

        int preSum = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i]; 

            int rem = preSum%k;

            if(rem<0){
                rem+=k;
            }

            ans+=um[rem];

            um[rem]++;
        }


        return ans;
    }
};