class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();

        if(n<=1){
            return "";
        }
        int ind = -1;

        for(int i=0;i<n/2;i++){
            if(s[i]!= 'a'){
                ind = i;
                break;
            }
        }

        if(ind!=-1){
            s[ind]='a';
        }
        else{
            s[n-1]='b';
        }
        return s;
    }
};