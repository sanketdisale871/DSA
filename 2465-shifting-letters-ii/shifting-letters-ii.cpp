class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>pref(n+1,0);

        for(auto it:shifts){
            int l = it[0];
            int r = it[1];

            if(it[2]==0){
                pref[l]-=1;
                pref[r+1]+=1;
            }
            else{
                pref[l]+=1;
                pref[r+1]-=1;
            }
        }

        for(int i=1;i<=n;i++){
            pref[i]+=pref[i-1];
        }

        string str = s;

      

        for(int i=0;i<n;i++){
            int ind = i;
            
            int changeBy = (str[ind]-'a'+pref[i])%26;

            changeBy = (changeBy+26)%26;
            str[ind]='a'+changeBy;
        }  
        return str;      
    }
};