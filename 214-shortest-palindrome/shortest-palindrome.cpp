class Solution {
    private:
    vector<int>kmp(string str){
        int n = str.length();
        vector<int>lps(n,0);

        for(int i=1;i<n;i++){
            int prevInd = lps[i-1];

            while(prevInd>0 && str[i]!=str[prevInd]){
                prevInd = lps[prevInd-1];
            }
            lps[i]=prevInd+(str[i]==str[prevInd]?1:0);
        }
        return lps;
    }

public:
    string shortestPalindrome(string s) {
        string ans="";
        string temp = s;
        reverse(temp.begin(),temp.end());
        string str = s + "#" + temp;

        vector<int>lpsVe = kmp(str);

        int maxiLen = lpsVe[lpsVe.size()-1];

        

        int chrUch = s.length()-maxiLen;
        int itr = s.length()-1;
        
        while(chrUch--){
            ans.push_back(s[itr]);
            itr--;
        }

        ans = ans + s;

        return ans;
    }
};