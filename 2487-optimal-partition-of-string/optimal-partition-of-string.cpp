class Solution {
public:
    int partitionString(string s) {
        vector<int>occur(26,0);
        int cnt = 1;
        for(int i=0;i<s.length();i++){

            if(occur[s[i]-'a']!=0){
                cnt++;
                for(int i=0;i<26;i++){
                    occur[i]=0;
                }
            }
            occur[s[i]-'a']=1; 
        }

        return cnt;
    }
};