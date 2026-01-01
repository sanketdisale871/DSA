class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int>preCnt1(n,0);
        vector<int>preCnt0(n,0);
        int cnt1 = 0;
        int cnt0 = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
                cnt1 = 0;

                if(i-cnt0>=0){
                    if(preCnt1[i-cnt0]>=cnt0){
                        ans++;
                    }
                }

            }
            else{
                cnt1++;
                cnt0 = 0;

                if(i-cnt1>=0){
                    if(preCnt0[i-cnt1]>=cnt1){
                        ans++;
                    }
                }
            }
            preCnt1[i]=cnt1;
            preCnt0[i]=cnt0;
        }
        return ans;
    }
};