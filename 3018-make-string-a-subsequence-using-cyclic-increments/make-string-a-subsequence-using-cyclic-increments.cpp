class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(),n=str2.size();

        int i=0,j=0;

        while(i<m && j<n){
            char ch = str1[i];
            if(ch=='z'){
                ch = 'a';
            }
            else{
                ch++;
            }

            if(str1[i]==str2[j] || ch==str2[j]){
                j++;
                i++;
            }
            else{
                i++;
            }
        }

        if(j>=n){
            return true;
        }
        return false;
    }
};