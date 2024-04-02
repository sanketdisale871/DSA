class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        unordered_map<char,char>um;
        unordered_set<char>used;

        for(int i=0;i<s.length();i++){
            if(um.count(s[i])>0){
                if(um[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                if(used.count(t[i])){
                    return false;
                }
                um[s[i]]=t[i];
                used.insert(t[i]);
            }
        }

        return true;
    }
};