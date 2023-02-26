


class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        
        vector<int>div(n,0);
        
        long sm = 0;
        
        for(int i=0;i<n;i++){
            sm = ((sm*10)+(word[i]-'0'))%m;
            
            if(sm==0){
                div[i]=1;
            }
        }
        return div;
    }
};
