class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>um;

        for(auto ch:s){
            um[ch]++;
        }

        for(int i=0;i<s.length();i++){
            if(um[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};