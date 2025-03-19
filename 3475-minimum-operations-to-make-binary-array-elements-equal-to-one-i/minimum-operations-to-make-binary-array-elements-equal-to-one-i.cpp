class Solution {
public:
    int minOperations(vector<int>& nums) {
       int cnt = 0;
        int i=0;
        for(;i<nums.size()-2;i++){
            if(nums[i]==0){
                cnt++;

                for(int j=i;j<i+3 && j<nums.size();j++){
                    nums[j]=!nums[j];
                }
            }
        }
        while(i<nums.size()){
            if(nums[i]==0){
                return -1;
            }
            i++;
        }
        return cnt;
    }
};