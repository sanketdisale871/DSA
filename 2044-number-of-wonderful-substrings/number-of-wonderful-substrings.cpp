class Solution {
public:
    typedef long long int ll;
    long long wonderfulSubstrings(string word) {
        ll n = word.length();

        unordered_map<ll,ll>um; // um [mask] = occurance 

        ll mask = 0;

        ll ans = 0;

        um[0]=1;

        for(ll i=0;i<n;i++){
            ll ind = word[i]-'a';

            mask = mask ^ (1<<ind);

            if(um.count(mask)){ // Even wale case ke liye, sb characters even hai.
                ans += um[mask];
            }

            // Odd ke liye, mai (1-10) tk Mask lagake dekhata 
            for(ll j=0;j<=9;j++){
                ll temp = mask ^ (1<<j);

                if(um.count(temp)){
                    ans+=um[temp];
                }
            }

            um[mask]++;
        }
        return ans;
    }
};