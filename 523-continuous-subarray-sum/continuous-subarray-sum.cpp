class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // <prefSum,k>
        unordered_map<int,int>um;

        int pr = 0;

        for(int i=0;i<nums.size();i++){
            pr+=(nums[i]);

            if(pr%k == 0 && (i-0+1)>1){ // When any subarray from starting, e.g [23,2,4,6,6] and k = 7 ==> {23,2,4,6}
                return true;
            }

            if(um.find(pr%k)!=um.end()){

                if((i-um[pr%k])>1){
                    return true;
                }
            }
            else{
                um[pr%k]=i;
            }

        }
        return false;
    }
};