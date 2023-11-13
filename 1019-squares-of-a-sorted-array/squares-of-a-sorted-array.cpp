class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);

        int i=0,j=n-1,k=n-1;

        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                ans[k]=nums[i]*nums[i];
                i++;
            }
            else{
                ans[k]=nums[j]*nums[j];
                j--;
            }
            k--;
        }
        return ans;
    }
};