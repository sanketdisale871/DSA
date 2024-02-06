class Solution {
public:
    int minOperations(int n) {
        int addOper = 0;

        // 1110111 => By Adding 1 to 0Th bit position => 1111000 , After adding 1 to the 4Th Position, => 100000000  , Now after substracting => 0.   

        for(int i=0;i<20;i++){
            if(__builtin_popcount(n+(1<<i)) < __builtin_popcount(n)){
                addOper++;
                n+=(1<<i);
            }
        }

        int subOp = __builtin_popcount(n);
        return subOp+addOper;
    }
};