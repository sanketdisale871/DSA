class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>um;
        int cnt = 0;

        for(auto ch :s){
            um[ch]++;
        }

        for(auto ch : t){
            if(um.find(ch)!=um.end()){
                um[ch]--;

                if(um[ch]==0){
                    um.erase(ch);
                }
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};