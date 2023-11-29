class Solution {
    // DSA Student : Sanket Disale
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while(n){
            if((n & (1<<0))){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
};