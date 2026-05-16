class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElem = *min_element(nums.begin(),nums.end());

        return minElem;
    }
};