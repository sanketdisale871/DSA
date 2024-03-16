class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*
        My Approach: 
        1) 
        
        */

        int totArrayLen = nums.size();
        unordered_map<int,int>hashMap;

        hashMap[0]=-1;

        int cnt1=0;
        int cnt0=0;

        int maxiLen = 0;

        for(int i=0;i<totArrayLen;i++){
            if(nums[i]==1){
                cnt1++;
            }
            else{
                cnt0++;
            }

            int diff = cnt1-cnt0;

            if(hashMap.find(diff)!=hashMap.end()){
                int res = i-hashMap[diff];

                maxiLen = max(maxiLen,res);
            }
            else{
                hashMap[diff]=i;
            }
        }

        return maxiLen;
    }
};