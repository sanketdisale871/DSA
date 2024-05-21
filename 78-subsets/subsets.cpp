class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sizOfArray = nums.size();
        int totElems = (1<<sizOfArray); // 

        vector<vector<int>>ans; // Total Subsets 

        for(int mask = 0;mask<totElems;mask++){
            vector<int>temp;
            for(int itr=0;itr<sizOfArray;itr++){
                if(mask & (1<<itr)){
                    temp.push_back(nums[itr]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};