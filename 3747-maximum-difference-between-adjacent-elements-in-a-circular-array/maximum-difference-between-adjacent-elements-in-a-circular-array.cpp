class Solution {
public:
/*
Understanding: 
In given an array, Maximum absolute diff. circular.
// What wil be the array size, 
// range of numbers in array
//
[1,2,4]
0  1  2

=> 
i = 1, maxi= INT_MIN
diff = 1, maxi = 1

i = 2 , maxi = 1
diff = 2 , maxi = 2

diff = 3, maxi = 3

return maxi

T.C : O(n)
S.C : O(1)
*/
    int maxAdjacentDistance(vector<int>& nums) {
        int numsSize = nums.size();
        int maxiAbsDiff = abs(nums[0]-nums[numsSize-1]);

        for(int itrNums=1;itrNums<numsSize;itrNums++){
            int diff = abs(nums[itrNums]-nums[itrNums-1]);
            maxiAbsDiff = max(maxiAbsDiff,diff);
        }
        return maxiAbsDiff;
    }
};