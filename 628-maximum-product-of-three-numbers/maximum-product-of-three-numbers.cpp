class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Finding the three Nums who has product is maximum
        // Let's see how I can find them...
        int n = nums.size();
        // All are positive => max number only in cosideration
        // Negative, 2 negative and one positive
        /// If all are negative, minimum one 
        sort(nums.begin(),nums.end());

        int num1 = nums[0];
        int num2 = nums[1];
        int num3 = nums[2];

        int res = num1*num2*num3;
        int ans = res;

        for(int i=3;i<nums.size();i++){
            num1 = num2;
            num2 = num3;
            num3 = nums[i];

            res = num1*num2*num3;
            ans = max(ans,res);
        }

        res = nums[0]*nums[1]*nums[n-1];
        ans = max(ans,res);

        return ans;
    }
};