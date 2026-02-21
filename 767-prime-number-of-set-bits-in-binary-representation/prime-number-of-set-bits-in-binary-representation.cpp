class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int>isPrime(1e6,1);
        isPrime[0]=0;
        isPrime[1]=0;
        // isPrime[2]=1;
        for(int i=2;i<1e6;i++){
            if(isPrime[i]){
                for(int j = 2*i;j<1e6;j+=i){
                    isPrime[j]=0;
                }
            }
        }

        int ans =0;

        for(int i=left;i<=right;i++){
            int setBits = __builtin_popcount(i);

            if(isPrime[setBits]){
                ans++;
            }
        }
        return ans;
    }
};