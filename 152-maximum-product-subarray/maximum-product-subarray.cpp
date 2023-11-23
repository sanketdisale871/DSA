class Solution {
public:
typedef long long int ll;
    int maxProduct(vector<int>& nums) {
        ll frwrd = 1;
        ll maxi = INT_MIN;
        ll bacwrd = 1;

        for(ll i=0;i<nums.size();i++)
        {
            frwrd*=nums[i];
            bacwrd*=nums[nums.size()-i-1];
            maxi = max({maxi,frwrd,bacwrd});
            if(frwrd==0){
                frwrd=1;
            }
            if(bacwrd==0){
                bacwrd=1;
            }
        }

        return (int)maxi;
    }
};