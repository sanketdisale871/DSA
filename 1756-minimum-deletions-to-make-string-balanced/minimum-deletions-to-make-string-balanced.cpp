class Solution {
public:
    int minimumDeletions(string s) {
        int ans = INT_MAX;

        int n = s.length();

        if(n==1){
            return 0;
        }

        vector<int>prefA(n,0);
        vector<int>suffB(n,0);

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                cnt++;
            }
            prefA[i]=cnt;
        }

        cnt = 0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                cnt++;
            }
            suffB[i]=cnt;
        }

        for(int i=0;i<n-1;i++){
            int oper = prefA[i]+suffB[i+1];

            ans = min(ans,oper);
        }

        ans = min(ans,prefA[n-1]);
        ans = min(ans,suffB[0]);

        return ans;
    }
};