class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dupli = -1;
        int misi = -1;

        unordered_map<int,int>um;

        for(auto num:nums){
            um[num]++;
        }

        for(int i=1;i<=nums.size();i++){
            if(um[i]==0){
                misi = i;
            }
            else if(um[i]>1){
                dupli = i;
            }
        }

        return {dupli,misi};
    }
};