class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i=0,j=s.length()-1;

        while(s[i]==s[j] && i<j){
            char ch = s[i];

            while(i<=j && s[i]==ch){
                i++;
            }

            while(i<j && s[j]==ch){
                j--;
            }
        }
        // if(i==j){
        //     return 0;
        // }
        return j-i+1;
    }
};