class Solution {
public:
    typedef long long int ll;
    long long maxTotalValue(vector<int>& nums, int k) {
        ll maxiSum = 0;
        // Exactly 'k' Non-Empty subarrays I have to choose re, 
        // One element I have to fix, max(nums[l...r])-min(nums[l....r]);
        ll totVal = 0;

        // Sum of chosen values bhaiiiiii!!!!!!!!
        // I have to generatet the 
        // 'k' Subarrays i have to generate bhaiii

        int minElem = *min_element(nums.begin(),nums.end());
        int maxElem = *max_element(nums.begin(),nums.end());

        int diff = maxElem-minElem;

        ll res = k*1LL*diff;

        return res;
    }
};