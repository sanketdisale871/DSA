class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         // Counter for keeping track of elements other than val
        int count = 0;
        // Loop through all the elements of the array
        for (int i = 0; i < nums.size(); i++) {
            // If the element is not val
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};