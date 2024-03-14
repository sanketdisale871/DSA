class Solution {
public:
    int atMost(vector<int>&nums,int goal){
        
        int stItr=0,edItr=0,totNums = nums.size();

        int totSub = 0;
        int sum = 0;

        while(edItr<totNums){
            sum+=nums[edItr];

            if(sum<=goal){
                totSub+=(edItr-stItr+1);
                edItr++;
            }
            else{
                while(sum>goal && stItr<=edItr){
                    sum-=nums[stItr];
                    stItr++;
                }
                totSub +=(edItr-stItr+1);
                edItr++;
            }
        }
        return totSub;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};