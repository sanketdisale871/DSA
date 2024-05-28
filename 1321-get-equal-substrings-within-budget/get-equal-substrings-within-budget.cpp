class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int maxiLen = 0;

        int n = s.length();

        int cst = 0;

        while(j<n){
            cst+=abs(s[j]-t[j]);

            if(cst<=maxCost){
                int len = j-i+1;
                maxiLen = max(maxiLen,len);
                j++;
            }
            else{
                while(i<=j && cst>maxCost){
                    cst-=abs(s[i]-t[i]);
                    i++;
                }
                // maxiLen = max(maxiLen,j-i+1);
                j++;
            }
        }
        return maxiLen;
    }
};