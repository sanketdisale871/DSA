class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>um;

        int keepCnt=0;

        for(int i=0;i<nums.size();i++){
            if(um.find(nums[i])!=um.end()){
                for(auto it:um[nums[i]]){
                    if((it*i)%k==0){
                        keepCnt++;
                    }
                }
            }

            um[nums[i]].push_back(i);
        }
        return keepCnt;


    }
};