class Solution {
public:
    typedef long long int ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll cnt = 0;
        ll sum = 0;

        ll minDecr =  INT_MAX;

        for(auto it:nums){
            if((it^k)>it){
                sum+=(it^k);
                cnt++;

                minDecr = min(minDecr,(ll)(it^k)-it);
            }
            else{
                sum+=it;

                minDecr = min(minDecr,(ll)it-(it^k));
            }
        }

        if(cnt%2==0){
            return sum;
        }
        return sum-minDecr;
    }
};