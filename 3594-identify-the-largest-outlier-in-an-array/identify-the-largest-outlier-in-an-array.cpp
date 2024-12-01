class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,bool>um;
        int res = -1001;

        int totSum = accumulate(nums.begin(),nums.end(),0);

        for(auto it:nums){
            int out = totSum - 2*it;

            if(um[out]>0){
                res = max(res,out);
            }

            int sum = (totSum-it)/2;

            if(2*sum+it == totSum && um[sum]>0){
                res = max(res,it);
            }

            um[it]=1;
        }
        return res;
    }
};