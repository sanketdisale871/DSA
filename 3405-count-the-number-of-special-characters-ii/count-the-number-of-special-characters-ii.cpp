class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();

        // unordered_map<int,int>lwr;
        // unordered_map<int,int>upr;

        vector<int>lwr(26,-1);
        vector<int>upr(26,-1);
        
     
        
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            
            if(ch>='a' && ch<='z'){
                lwr[ch-'a']=i;
            }
            else{
                if(upr[ch-'A']==-1){
                    upr[ch-'A']=i;
                }                
              }
            }

        int cnt = 0;
        
        for(int i=0;i<26;i++){
            if(lwr[i]!=-1 && upr[i]!=-1 && lwr[i]<upr[i]){
                cnt++;
            }
        }
        
        
        return cnt;
    }
};