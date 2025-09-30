class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();


        for(int i=n-1;i>=1;i--){
            vector<int>newArr(i,0);
            
            for(int itr=0;itr<nums.size()-1;itr++){
                int newSum = (nums[itr]+nums[itr+1])%10;
                newArr[itr]=newSum;
            }
            nums = newArr;
        }
        return nums[0];     
    }
};