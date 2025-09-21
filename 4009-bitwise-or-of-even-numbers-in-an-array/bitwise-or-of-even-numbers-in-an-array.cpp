class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int btOr = 0;

        for(auto it:nums){
            if(it%2==0){
                btOr|=it;
            }
        }
        return btOr;
    }
};