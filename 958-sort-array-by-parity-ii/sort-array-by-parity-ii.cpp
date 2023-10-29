class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        int i=0,j=1;

        for(auto it : nums){
            if(it%2==0){
                ans[i]=it;
                i+=2;
            }
            else{
                ans[j]=it;
                j+=2;
            }
        }

        return ans;
    }
};