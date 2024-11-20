class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;

        int i=0;
        while(i<n){
            if(s[i]=='a'){
                cnta++;
            }
            else if(s[i]=='b'){
                cntb++;
            }
            else{
                cntc++;
            }
            i++;
        }

        if(cnta<k || cntb<k || cntc<k){
            return -1;
        }

        int ans = n;
        i = n-1;
        int j = n-1;

        while(i>=0){
            if(s[i]=='a'){
                cnta--;
            }
            else if(s[i]=='b'){
                cntb--;
            }
            else{
                cntc--;
            }

            i--;

            while(cnta<k || cntb<k || cntc<k){
                if(s[j]=='a'){
                    cnta++;
                }
                else if(s[j]=='b'){
                    cntb++;
                }
                else{
                    cntc++;
                }
                j--;
            }

            int res = i +n - j;

            ans = min(ans,res);
        }
        return ans;
    }
};