class Solution {
public:
    int smallestNumber(int n) {
        int x = n;

        int msbBit = log2(x);

        for(int i=0;i<msbBit;i++){
            int msk = x & (1<<i);

            if(!msk){
                x = x|(1<<i);
            }
        }
        return x;
    }
};