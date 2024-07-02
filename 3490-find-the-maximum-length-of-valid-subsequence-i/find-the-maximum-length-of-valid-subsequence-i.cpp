class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cntOdd=0,cntEven=0,cntAlt = 0;
        int prevNum = -1;

        for(auto it:nums){
            if(it&1)
            {
                cntOdd++;

                if(prevNum!=1){
                    cntAlt++;
                    prevNum = 1; // 1 for I pickedUp, Odd Number last
                }
            }
            else{
                cntEven++;

                if(prevNum!=0){
                    cntAlt++;
                    prevNum = 0; // 0 for I pickedUp, Even Number last
                }
            }
        }

        return max(cntOdd,max(cntEven,cntAlt));
    }
};