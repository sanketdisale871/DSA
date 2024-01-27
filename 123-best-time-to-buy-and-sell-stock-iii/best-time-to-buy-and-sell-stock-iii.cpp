class Solution {
    private:
    typedef long long int ll;

    ll dp[100002][3][3];
    ll profit(ll ind,vector<int>&pr,ll buy,ll noTran){
        if(ind>= pr.size()){
            return 0;
        }

        if(noTran<=0){
            return 0;
        }

        if( dp[ind][buy][noTran]!=-1){
            return  dp[ind][buy][noTran];
        }

        if(buy){
            ll opt1 = (-pr[ind]+profit(ind+1,pr,0,noTran));
            ll opt2 = profit(ind+1,pr,1,noTran);

            return dp[ind][buy][noTran]=max(opt1,opt2);
        }
        else{
            ll opt1 = (pr[ind]+profit(ind+1,pr,1,noTran-1));
            ll opt2 = profit(ind+1,pr,0,noTran);

            return dp[ind][buy][noTran]=max(opt1,opt2);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        
        for(ll i=0;i<100002;i++){
            for(ll j=0;j<3;j++){
                for(ll k=0;k<3;k++){
                    dp[i][j][k]=-1;
                }
            }
        }


        return profit(0,prices,1,2);
    }
};