class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int miniSco = INT_MAX;

        for(int i=k-1;i<nums.size();i++){
            int diff = nums[i]-nums[i-k+1];
            miniSco = min(miniSco,diff);
        }
        return miniSco;
    }
};