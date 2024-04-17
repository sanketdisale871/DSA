class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int ans = 0;

        int i=0,j=0;
        unordered_map<char,int>um;

        while(j<n){
            um[s[j]]++;

            if(um.size()<3){
                j++;
            }
            else{
                while(um.size()>=3 && i<=j){
                    ans+=(n-j);

                    um[s[i]]--;

                    if(um[s[i]]==0){
                        um.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }

        return ans;
    }
};