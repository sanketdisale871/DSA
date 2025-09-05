class Solution {
public:
    int minBitFlips(int start, int goal) {
        int minFlips = 0;

        for(int bit=0;bit<32;bit++){
            bool isStBitSet = (start & (1<<bit))?1:0;
            bool isGoBitSet = (goal & (1<<bit))?1:0;

            if((isStBitSet && isGoBitSet) || (!isStBitSet && !isGoBitSet)){
                continue;
            }
            else{
                minFlips++;
            }        
        }
        return minFlips;
    }
};