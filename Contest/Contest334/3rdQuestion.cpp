/* 
INTUTION

1) We only make n / 2 pairs, So, We marked element from i = 0 for first element & j = n/2 for second element if nums[i] * 2 <= nums[j] is valid then we increment i & j.
but it's invalid then we know that next element of j is greater, so in that case we increament j pointer.

This intution from @votrubac

1) Intuition for this problem is tricky.

2) Indices i and j form a pair (if 2 * nums[i] < nums[j]). If we want to make m pairs, the best strategy is to pick m smallest numbers as nums[i].

3) At the same time, we cannot make more than n / 2 pairs. Therefore, we consider n - n / 2 largest numbers for nums[j].
So, we sort the array, and greedily match smallest numbers with numbers in the second half of the sorted array.

e.g. : 1,2,3,4,5,6,7,8

Maximum Possible pairs : 
 1 <-> 5
 2 <-> 6
 3 <-> 7
 4 <-> 8
 
*/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int i = 0;
        int j = n/2;
        int ans = 0;

        while(i< n/2 && j<n){
            if(2*nums[i]<=nums[j]){
                ans+=2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
     
    }
};
