class Solution {
    /*
    Refer Solution: https://www.youtube.com/watch?v=z0cdra6jHs4
    */
public:
    typedef long long int ll;
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll instStVal=0;
        ll maxiVal = 0;
        ll miniVal = 0;

        for(auto it:differences){
            instStVal+=it;
            maxiVal = max(maxiVal,instStVal);
            miniVal = min(miniVal,instStVal);
        }

        ll res = (upper-lower)-(maxiVal-miniVal)+1;
        ll ans = max(res,1ll*0);

        return (int)ans;
    }
};