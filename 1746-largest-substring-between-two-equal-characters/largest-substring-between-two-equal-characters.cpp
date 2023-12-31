class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>um;

        int maxLen = -1;

        for(int i=0;i<s.length();i++){
            char ch = s[i];

            if(um.find(ch)!=um.end()){
                int res = i-um[ch]-1;
                maxLen = max(maxLen,res);
            }
            else{
                um[ch]=i;
            }
        }
        return maxLen;
    }
};