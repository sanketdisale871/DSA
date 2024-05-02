class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;

        unordered_map<int,int>um;

        for(auto it:nums){
            if(it>0){
                int negNum = -1*it;

                if(it>maxi && um.count(negNum)){
                    maxi = it;
                }
            }
            else{
                int posNum = -1*it;
                if(posNum>maxi && um.count(posNum)){
                    maxi = posNum;
                }
            }

            um[it]++;
        }

        return maxi;
    }
};