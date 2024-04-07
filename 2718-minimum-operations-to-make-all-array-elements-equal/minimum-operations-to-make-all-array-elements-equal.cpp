class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n=nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> prefixSum(n+1);

        prefixSum[0] = 0;

        for (int i=1;i<=n;++i) {
            prefixSum[i] = prefixSum[i-1] + (nums[i-1]) ; 
        }

        for (long long q:queries) {
            auto itr = upper_bound(nums.begin(), nums.end(),q); 
            int idx = itr-nums.begin(); 
            long long left= idx*q-prefixSum[idx]; 
            long long right= (prefixSum[n]-prefixSum[idx])-(n-idx)*q; 
            ans.push_back(left + right);
        }
        return ans;
    }
};