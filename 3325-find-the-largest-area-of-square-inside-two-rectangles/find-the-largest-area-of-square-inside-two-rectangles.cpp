class Solution {
public:
    typedef long long int ll;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        ll n = bottomLeft.size();
        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){

                int newBtx = max(bottomLeft[i][0],bottomLeft[j][0]);
                int newBty = max(bottomLeft[i][1],bottomLeft[j][1]);
                int newRtx = min(topRight[i][0],topRight[j][0]);
                int newRty = min(topRight[i][1],topRight[j][1]);
                
                if(newBtx<newRtx && newBty<newRty){
                    ll side = min(newRtx-newBtx,newRty-newBty);
                    ll res = side*1ll*side;
                    ans = max(ans,res);
                }
            }
        }
        return ans;
    }
};