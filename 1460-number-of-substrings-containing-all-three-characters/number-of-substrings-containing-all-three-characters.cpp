class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int i=0,j=0;

        unordered_map<char,int>um = {
            {'a',1},{'b',1},{'c',1}
        };
        int cnt = 3;
        int ans = 0;


        while(j<n){
            um[s[j]]--;

            if(um[s[j]]==0){
                cnt--;
            }

            if(cnt>0){
                j++;
            }
            else{

                    while(i<=j && cnt<=0){
                        ans+=(n-j);

                    um[s[i]]++;

                    if(um[s[i]]==1){
                        cnt++;
                    }
                    i++;
                    }
                    
                
                j++;
            }
        }
        return ans;
    }
};