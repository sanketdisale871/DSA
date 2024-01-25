class Solution {
public:
    typedef long long int ll;
    int characterReplacement(string s, int k) {
        ll n = s.length();
        ll i=0,j=0;
        ll ans = 0;
        unordered_map<char,ll>um;
        ll maxiOccur = 0;

        while(j<n){
            um[s[j]]++;

            maxiOccur = max(maxiOccur,um[s[j]]);

            if((j-i+1)-maxiOccur<=k){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                
                while((j-i+1)-maxiOccur>k && i<=j){
                    um[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};