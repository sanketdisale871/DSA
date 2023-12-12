class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return a>b;
        });

        int num1 = nums[0]-1;
        int num2 = nums[1]-1;

        return num1*1ll*num2;
    }
};