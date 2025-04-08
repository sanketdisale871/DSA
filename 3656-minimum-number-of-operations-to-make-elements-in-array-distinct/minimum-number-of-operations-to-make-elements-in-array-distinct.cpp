class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>occrNums;
        unordered_map<int,int>um;

        int keepTrack = -1;

        for(int itr=0;itr<nums.size();itr++){
            if(um.find(nums[itr])!=um.end()){
                keepTrack = max(keepTrack,um[nums[itr]]);
            }
           um[nums[itr]]=itr;
        }

        keepTrack++;

        cout<<keepTrack<<endl;

        int rqOper = (int)ceil(keepTrack*1.0/3);

        return rqOper;

    }
};