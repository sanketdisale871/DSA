class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>temp(n+1,0);
        vector<int>temp1(n+1,0); 


        for(auto it:trust){
            temp[it[1]]++;
            temp1[it[0]]++;
        }

        for(int i=1;i<=n;i++){
            if(temp[i]>=(n-1) && temp1[i]==0){
                return i;
            }
        }
        return -1;
    }
};