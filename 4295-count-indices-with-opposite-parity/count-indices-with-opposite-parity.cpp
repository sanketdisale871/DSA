class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            int cnt = 0;
            bool isOdd = (nums[i]&1)==1?true:false;
            for(int j=i+1;j<n;j++){
                bool isOddSec = (nums[j]&1)==1?true:false;

                if((isOdd && !isOddSec)|| (!isOdd && isOddSec)){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};