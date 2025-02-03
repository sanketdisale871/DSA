class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        /*
        Understanding : Given an array, 
        Goal: Find out the lognest subarray length, which is Strictly increasing or Strictly decreasing.

        Questions: 
        1) What would be the array size? , 1e5
        2) What is the number range?

        Brute Force Approach:
        1) Every number is the end point of my strictly increasing/decreasing array
        2) MaxiLength for each number, And Final will consider the one of these. 

        T.C : O(n2)
        S.C: O(1)


        Optimal Approach:
        1) Forward direction, and will calculate the strictly increasing and strictlu descriong, same strore in varainale, and according need will come out.
        */
        int stIncr = 1;
        int stDecr = 1;
        int ans = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                stIncr++;
                stDecr=1;
            }
            else if(nums[i]<nums[i-1]){
                stDecr++;
                stIncr=1;
            }
            else{
                stDecr=1;
                stIncr=1;
            }

            ans = max({ans,stIncr,stDecr});
        }
        

        return ans;
    }
};