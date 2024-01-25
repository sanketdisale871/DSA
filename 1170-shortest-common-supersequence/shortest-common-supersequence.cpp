class Solution {
    private:
    typedef long long int ll;
/* Approach : 
i) Find the Longest Common Subsequence, dp[i][j] => Tell the longest common subsequence when, 
'i' from first string and 'j' from second string.

*/
    string findLCS(int n, int m,string &s1, string &s2){
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }


        ll i=n,j=m;
        
        string str = "";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                str.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{ 
                // Going where i am coming with larger answer
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }


        reverse(str.begin(),str.end());

        return str;	
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcsString = findLCS(str1.length(),str2.length(),str1,str2);

        string res = "";
        ll i=0,j=0;
        for(auto ch:lcsString){
            
            while(ch!=str1[i]){
                res.push_back(str1[i]);
                i++;
            }

            while(ch!=str2[j]){
                res.push_back(str2[j]);
                j++;
            }

            res.push_back(ch);
            i++;
            j++;
        }

        res+=str1.substr(i)+str2.substr(j);

        return res;
    }
};