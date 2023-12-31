class Solution {
    private:
    typedef long long int ll;
    bool isPossible(string &s,int len){
        ll i=0,j=0,n=s.length();

        unordered_map<char,int>um;
        vector<int>occr(26,0);

        while(j<n){
            um[s[j]]++;

            if(j-i+1 < len){
                j++;
            }
            else{

                if(um.size()==1){
                    occr[s[j]-'a']++;

                    if(occr[s[j]-'a']>2){
                        return true;
                    }
                }

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
public:
    int maximumLength(string s) {
        ll n = s.length();

        ll low = 1;
        ll high=n-2;

        ll ans = -1;

        while(low<=high){
            ll mid = (low+high)/2;

            if(isPossible(s,mid)){
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