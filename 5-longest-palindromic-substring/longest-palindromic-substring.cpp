class Solution {
    private:
    bool isPalin(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int maxiLen  = 1;
        int stPoint = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPalin(i,j,s)){
                    if((j-i+1)>maxiLen){
                        maxiLen = j-i+1;
                        stPoint = i;
                    }
                }
            }
        }

        return s.substr(stPoint,maxiLen);
    }
};