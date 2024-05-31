class Solution {
public:
    typedef long long int ll;
    vector<int> singleNumber(vector<int>& nums) {
        int num1=0,num2=0;

        ll xrr = 0;
        for(auto it:nums){
            xrr^=it;
        }

        ll bit = (xrr & (xrr-1) )^xrr;

        for(auto it:nums){
            if((it & bit)){
                num1^=it;
            }
            else{
                num2^=it;
            }
        }

        return {num1,num2};
    }
};