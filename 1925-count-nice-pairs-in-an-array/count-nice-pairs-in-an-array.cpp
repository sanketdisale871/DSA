class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map <int,long long> umap;
        
        for(int i =0;i<n;i++){
            string str = to_string(nums[i]);
            reverse(str.begin(),str.end());
            int rev = stoi(str);
            nums[i] = nums[i] - rev;
        }
        
        for(auto iter : nums){
            umap[iter]++;
        }
        
        long long ans = 0;
        long long mod = 1e9+7;
        
        for(auto iter : umap){
            if(iter.second<=1) continue;
            long long num = iter.second;
            long long temp = (num *(num-1))/2;
            ans+=temp;
            ans = ans % mod;
        }
        
        return ans%mod;
    }
};