class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
      
        int k = accumulate(nums.begin(),nums.end(),0)-x;

        if(k<0){
            return -1;
        }
        if(k==0){
            return nums.size();
        }
        int ans = -1;
        unordered_map<int,int>um;
        um[0]=-1;

        int prefSum = 0;

        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];

            int res = prefSum-k;
            if(um.find(res)!=um.end()){
                ans = max(ans,i-um[res]);
            }

            if(um.find(prefSum)==um.end()){
                um[prefSum]=i;
            }            
        }

        if(ans==-1){
            return ans;
        }

        return nums.size()-ans;
    }
};