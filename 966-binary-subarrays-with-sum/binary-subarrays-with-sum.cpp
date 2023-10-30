class Solution {
    private:
    int atMost(vector<int>&nums,int goal){
        int cnt = 0;
        int i=0,j=0;
        int n = nums.size();
        int sum = 0;

        while(j<n){
            sum+=nums[j];

            if(sum<=goal){
                cnt+=(j-i+1);
                j++;
            }
            else{
                while(sum>goal && i<=j){
                    sum-=nums[i];
                    i++;
                }
                cnt+=(j-i+1);
                j++;
            }
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};