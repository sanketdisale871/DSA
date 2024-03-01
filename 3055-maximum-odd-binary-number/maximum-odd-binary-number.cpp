class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                cnt1++;
                s[i]='0';
            }
        }
     

        for(int i=0;i<s.length()-1;i++){
            if(cnt1>1){
                s[i]='1';
                cnt1--;
                
            }
        }

        s[s.length()-1]='1';

        return s;
    }
};