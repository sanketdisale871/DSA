class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0; // Length of Last Word

        reverse(s.begin(),s.end());

        int itr = 0;

        while(s[itr]==' ' && itr<s.length()){
            itr++;
        }

        while(s[itr]!=' ' && itr<s.length()){
            len++;
            itr++;
        }


        return len;
    }
};