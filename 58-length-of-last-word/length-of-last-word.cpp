class Solution {
public:
    int lengthOfLastWord(string s) {
        
        string prev = "";
        string crr = "";

        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && i>0 && s[i-1]!=' '){
                prev = crr;
                crr = "";
            }
            else if(s[i]==' '){
                continue;
            }
            else{
                crr.push_back(s[i]);
            }
        }

        if(crr.length()>0){
            return crr.length();
        }

        return prev.length();
    }
};