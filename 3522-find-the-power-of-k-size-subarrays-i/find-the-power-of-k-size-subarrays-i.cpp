class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;

        int cons = 1;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if( i>0 &&nums[i]==nums[i-1]+1){
                cons++;
            }
            else{
                cons = 1;
            }


            if(i>=k-1){
                if(cons>=k){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }


        return ans;
    }
};