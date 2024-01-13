class Solution {
public:
    int minSteps(string s, string t) {
        // unordered_map<char,int>um;
        vector<int>um(26,0);
        int cnt = 0;

        for(auto ch :s){
            um[ch-'a']++;
        }

        for(auto ch : t){
            if(um[ch-'a']>0){
                um[ch-'a']--;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};