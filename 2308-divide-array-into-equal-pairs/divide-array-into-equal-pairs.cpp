class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>um;

        for(auto it:nums){
            um[it]++;
        }

        for(auto it:um){
            if(it.second%2!=0){
                return false;
            }
        }
        return true;
    }
};