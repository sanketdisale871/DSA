class Solution {
public:
    int maxDepth(string s) {
        int openPar =0 ; // count how many current expression have oper Parenth 
        int ans = 0;

        for(auto ch:s){
            if(ch=='('){
                openPar++;
            }
            else if(ch==')'){
                openPar--;
            }
            ans = max(ans,openPar); // Maximum Depth I Got 
        }
        return ans;
    }
};