class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;

        for(int bit=30;bit>=0;bit--){

            int stSet = (start & (1<<bit));
            int gSet = (goal & (1<<bit));

            if((stSet>0 && gSet>0) || (stSet==0 && gSet==0)){
                continue;
            }
            else{
                cnt++;
            }
        }


        return cnt;
    }
};