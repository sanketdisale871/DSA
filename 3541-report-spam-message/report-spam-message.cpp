class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st(bannedWords.begin(),bannedWords.end());

        int cnt = 0;

        for(auto it:message){
            if(st.count(it)>0){
                cnt++;
            }

            if(cnt>1){
                return true;
            }
        }
        return false;
    }
};