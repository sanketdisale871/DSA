class Solution {
public:
    typedef long long int ll;

    bool isPossible(ll mid,string s){
        unordered_map<char,int>um;
     
        vector<ll>occr(26,0);
        ll i=0,j=0,n = s.length();
        
        while(j<n){
            um[s[j]]++;

            if((j-i+1)<mid){
                j++;
            }
            else{
                if(um.size()==1){
                   occr[s[j]-'a']++;

                   if(occr[s[j]-'a']>=3){
                       return true;
                   }
                }
                // Sliding Step 
                um[s[i]]--;

                if(um[s[i]]==0){
                    um.erase(s[i]);
                }

                i++;
                j++;
            }
        }
        return false;
    }

    int maximumLength(string s) {
        
        ll n = s.length();
        ll low = 0;
        ll high = n;
        ll ans = -1;

        while(low<=high){
            ll mid = (low + high)/2;

            if(isPossible(mid,s)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};