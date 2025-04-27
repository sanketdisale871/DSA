class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        int cnt = 0;

        int len = 3;

        while(j<n){
            if(j-i+1<len){
                j++;
            }
            else{
                int sum = nums[i]+nums[j];

                if(nums[i+1]%2==0 && sum==nums[i+1]/2){
                    cnt++;
                }
                i++;
                j++;
            }
        }
        return cnt;
    }
};