class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>um;

        for(auto it:nums){
            um[it]++;
        }

        if(um.size()==n){
            return 0;
        }
        int oper = 0;

        for(int i=0;i<n;i+=3){
            int j = i;
            int cnt=3;
            while(cnt-- && j<n){
                um[nums[j]]--;

                if(um[nums[j]]==0){
                    um.erase(nums[j]);
                }
                j++;
            }

            if(cnt<3){
                oper++;
            }

            int len = n-j;

            if(len==um.size()){
                return oper;
            }
        }
        return oper;
    }
};