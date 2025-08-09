class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
        
        */
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char>mappingChars;
        set<char>usedChars;

        for(int i=0;i<s.length();i++){
            char firstChar = s[i];
            char secChar = t[i];

            if(mappingChars.find(firstChar)==mappingChars.end() && usedChars.count(secChar)==0){
                mappingChars[firstChar]=secChar;
                usedChars.insert(secChar);
            }
            else{
                if(mappingChars[firstChar]!=secChar){
                    return false;
                }
            }
        }
        return true;        
    }
};