class Solution {

/*
Think in terms of on and off. Turning on and turning off a switch. If a switch is already turned on, you can not turn it on again.

Given this: [2,5,2,1,1,4]

Go to index 0 and flip whatever value index 0 pointing to[if it was not flipped(turned on) before]...

What does that mean?

Index 0 has value 2. Flip whatever 2 is pointing-to. Since the array is 0 based, so we will flip 2-1 = 1 and that is 5.

So, our result will look like:[2,-5,2,1,1,4]
*/

public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>twiceNums;

        int n = nums.size();

        for(int i=0;i<n;i++){
            int ind = abs(nums[i])-1;

            if(nums[ind]<0){
                twiceNums.push_back(abs(nums[i]));
            }
            else{
                nums[ind]=-nums[ind];
            }
        }
        return twiceNums;
    }
};