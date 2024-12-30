class Solution {
public:
    typedef long long int ll;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp0(high+1,0);
        vector<ll>dp1(high+1,0);
        
        dp0[zero]=1; // No.of Strings, I can get when len 1
        dp1[one]=1;

        ll tot = 0;
        int mod = 1e9+7;

        for(int i=1;i<=high;i++){
            if(i-zero>=0){
                dp0[i]+=dp0[i-zero]+dp1[i-zero];
                dp0[i]%=mod;
            }

            if(i-one>=0){
                dp1[i]+=dp0[i-one]+dp1[i-one];
                dp1[i]%=mod;
            }

            if(i>=low && i<=high){
                tot+=dp0[i]+dp1[i];
                tot%=mod;
            }
        }
        return tot;

    }
};