class Solution {
public:
    int jump(vector<int>& nums) {
        // You're intially positioned at index 0.
        int jmpsRqrd = 0;
        int maxiJmp = 0;
        int currJmp = 0;

        for(int i=0;i<nums.size()-1;i++){
            maxiJmp = max(maxiJmp,nums[i]+i);

            if(currJmp<=i){
                currJmp = maxiJmp;
                jmpsRqrd++;
            }
        }
        return jmpsRqrd;
    }
};