class Solution {
public:
    typedef long long int ll;
    long long flowerGame(int n, int m) {
       ll en = m / 2, od = m - en, ans = 0;
        
        for(int i = 1; i <= n; i++){
            if(i % 2)ans += en;
            else ans += od;
        }
        return ans;
    }
};