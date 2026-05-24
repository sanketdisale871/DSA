class Solution {
public:
    int jump(vector<int>& nums) {
        int jmpRq = 0;
        int currJmp = 0;
        int maxiJmp = 0;

        for(int i=0;i<nums.size()-1;i++){
            maxiJmp = max(maxiJmp,nums[i]+i);

            if(currJmp<=i){
                currJmp = maxiJmp;
                jmpRq++;
            }

            if(currJmp<=i){
                return -1;
            }
        }
        return jmpRq;
    }
};