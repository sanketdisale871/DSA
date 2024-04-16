class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cst = 0;
        int maxiLen = 0;

        int j=0,i=0,n = s.length();

        while(j<n){
            cst+=abs(s[j]-t[j]);

            if(cst<=maxCost){
                maxiLen = max(maxiLen,j-i+1);
                j++;
            }
            else{
                while(i<=j && cst>maxCost){
                    cst-=abs(s[i]-t[i]);
                    i++;
                }
                j++;
            }
        }
        return maxiLen;
    }
};