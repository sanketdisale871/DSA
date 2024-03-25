class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int>twiceNums;

       sort(nums.begin(),nums.end()); // 

       // 1 2 3 2 3 => 1 2 2 3 3

       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            twiceNums.push_back(nums[i]);
        }
       }

        return twiceNums;
    }
};