class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        vector<vector<char>>dir = {{'N','W'},{'N','E'},{'W','S'},{'S','E'}};
        
        for(auto mkOpDr:dir){
            for(int i=0,curr=0,t=k;i<s.length();i++){
                if(mkOpDr[0]==s[i] || mkOpDr[1]==s[i]){
                        if(t>0){
                            t--;
                            curr++;
                        }
                        else{
                            curr--;
                        }
                }
                else{
                    curr++;
                }
                ans = max(ans,curr);
            }
        }



        return ans;
    }
};