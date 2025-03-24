class Solution {
public:
    int countDays(int days, vector<vector<int>>& meets) {
         int an4875s = 0;
        sort(meets.begin(),meets.end());

        if(meets[0][0]!=1){
            int re78rs = meets[0][0]-1;
            an4875s+=re78rs;
        }

        int maxer8i = meets[0][1];

        for(int i=1;i<meets.size();i++){
            if(meets[i][0]>maxer8i){
                int re78rs = meets[i][0]-maxer8i-1;
                an4875s+=re78rs;
            }

            maxer8i = max(maxer8i,meets[i][1]);
        }

        if(maxer8i!=days){
            int re78rs = days-maxer8i;
            an4875s+=re78rs;
        }
        
        return an4875s;
    }
};