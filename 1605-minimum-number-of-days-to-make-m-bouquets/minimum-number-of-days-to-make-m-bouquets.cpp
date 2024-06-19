class Solution {
    private:
    typedef long long int ll;

    bool isPossible(ll days,ll m,ll k,vector<int>&blDay){
        ll n = blDay.size();
        ll msBkts = 0;

        ll cnt = 0;

        for(ll i=0;i<n;i++){
            if(blDay[i]<=days){
                cnt++;
            }
            else{
                cnt=0;
            }

            // cout<<"i : "<<i<<" cnt : "<<cnt<<" msBkts : "<<msBkts<<endl;

            if(cnt>=k){
                msBkts++;
                cnt = 0;
            }
        }

        return msBkts>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll low = 0;
        ll high = *max_element(bloomDay.begin(),bloomDay.end());

        ll ans = -1;

        while(low<=high){
            ll mid = low + (high-low)/2;

            // cout<<"mid : "<<mid<<endl;

            if(isPossible(mid,m,k,bloomDay)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};