class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>sufOnes(n+1,0);

        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                sufOnes[i]=1+ sufOnes[i+1];
            }
            else{
                sufOnes[i]=sufOnes[i+1];
            }
        }

        int cntZeroes = 0;

        int totScore = 0;

        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                cntZeroes++;
            }

            int res = cntZeroes + sufOnes[i+1];

            totScore = max(totScore,res);
        }


        return totScore;
    }
};