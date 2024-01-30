class Solution {
public:
    int minOperations(int n) {
        int addOper = 0;

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