class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;

        int allXor=0;
        for(auto it:nums){
            allXor^=it;
        }

        int n = nums.size();
        int j = n-1;

        int i=0;

        while(i<n){
            int k=0;
            for(int bit=0;bit<maximumBit;bit++){
                if(allXor & (1<<bit)){
                    continue;
                }
                else{
                    k = k | (1<<bit);
                }
            }
            ans.push_back(k);
            allXor^=nums[j--];
            i++;
        }

        return ans;
    }
};