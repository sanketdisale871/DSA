class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxiJmp = 0;
        int currJmp = 0;

        int jmp = 0;

        for(int i=0;i<n-1;i++){
            maxiJmp = max(maxiJmp,nums[i]+i);

            if(currJmp==i){
                currJmp = maxiJmp;
                jmp++;
            }
        }


        return jmp;
    }
};