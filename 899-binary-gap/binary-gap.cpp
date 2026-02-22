class Solution {
public:
    int binaryGap(int n) {
        // Return the Longest distance between any two adjacent 1'2 binary representation 
        int firOcr = -1;
        int secOcr = -1;
        int maxiLen = 0;

        for(int i=0;i<32;i++){
            if(n & (1<<i)){
                if(firOcr==-1){
                    firOcr = i;
                }
                else{
                    secOcr = i;
                    int len = secOcr-firOcr;
                    maxiLen = max(maxiLen,len);
                    firOcr = secOcr;
                }
            }
        }
        return maxiLen;
    }
};