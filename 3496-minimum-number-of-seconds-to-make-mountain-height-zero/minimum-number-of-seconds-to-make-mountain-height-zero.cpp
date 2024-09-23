class Solution {
    private:
    typedef long long int ll;

    ll findMaxiRed(ll md,ll t){
        ll low = 0;
        ll high = 1e6;
        ll ans = low;

        while(low<=high){
            ll mid = low + (high-low)/2;

            ll res = t*(mid*(mid+1)/2);

            if(res<=md){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    bool isPossible(ll mtHt,ll mid,vector<int>&wrTime){
        
        for(ll i=0;i<wrTime.size();i++){
            ll maxRedu = findMaxiRed(mid,wrTime[i]);
            mtHt-=maxRedu;

            if(mtHt<=0){
                return true;
            }
        }
        return false;
    }
public:

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0;
        ll high = 1e18;
        ll ans = low;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(isPossible(mountainHeight,mid,workerTimes)){
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