class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int i=0,j=n-1;
        int itr = n-1;

        while(i<=j){
            int num1 = abs(nums[i]);
            int num2 = abs(nums[j]);

            if(num1>num2){
                res[itr]=(num1*num1);
                i++;
            }
            else{
                res[itr]=(num2*num2);
                j--;
            }
            itr--;
        }

        return res;
    }
};