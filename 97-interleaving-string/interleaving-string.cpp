/*
So you need to ask yourself ..why is dp used here?
In first look this questions looks pretty simple and can be done using 2 pointers.

Then you implement the 2 pointer approach and upon submission your code get a wrong ans on the below testcase.

This test case then tells you why this que is asking for a dp solution.

s1 = "aabc"
s2 = "abad"
s3= "aabadabc"

Now in this, if you start moving from the back using the 2 pointer approach, it keeps on eleminating the character from the 1st string i.e s1. But when s1 gets exhausted, your s3 does not match with s2.
Here you take a note that, when char at s1 and s2 are equal, we need to check if deleting the char from s1 is a correct move or deleting the char from s2 would be a correct move.

That clearly means, we have 2 choices here, either to delete the char from s1 or s2.


// Why |n-m| <=1, Debugger skills : if you divide the first string in 'n' parts, then obivously other string will placed in the gaps crated by first string. This gaps 'm'

*/


class Solution {
public:
    typedef long long int ll;
    ll dp[105][105];

    bool isInterleave(string s1, string s2, string s3) {
        ll len1 = s1.length();
        ll len2 = s2.length();
        ll len3 = s3.length();

        if(len3 != (len1+len2)){
            return false;
        }
     

        memset(dp,0,sizeof(dp));

        
            for(ll i=0;i<=len1;i++){
                for(ll j=0;j<=len2;j++){
                    if(i==0 && j==0){
                        dp[i][j]=1;
                    }
                    else if(i==0){

                        if(s2[j-1] == s3[i+j-1]){
                            dp[i][j]=dp[i][j-1];
                        }

                    }
                    else if(j==0){
                        if(s1[i-1]==s3[i+j-1]){
                            dp[i][j]= dp[i-1][j];
                        }
                    }
                    else{
                        dp[i][j]= (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                    }
                }
            }
        


        return dp[len1][len2];
        
    }
};