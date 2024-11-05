class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;

        int cnt1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
            }

            if(i&1){
                ans+=(cnt1%2);
                cnt1=0;
            }
        }
        return ans;
    }
};