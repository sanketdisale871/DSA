class Solution {
public:
    typedef long long int ll;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        ll n = tasks.size();
        ll m = shifts.size();
        vector<ll>pref(n,0LL);
        vector<int>ans(m,0);
        pref[0]=tasks[0];

        for(ll i=1;i<n;i++){
            pref[i]+=tasks[i];
            pref[i]+=pref[i-1];
        }

        ll totWork = pref[n-1];

        ll completedWork = 0LL;

        for(ll j=0;j<m;j++){
            completedWork+=shifts[j];

            if(completedWork>=totWork){
                ans[j]=0;
                completedWork = 0LL;
            }
            else{
                auto idx = upper_bound(pref.begin(),pref.end(),completedWork)-pref.begin();

                ll unfinished = n-idx;

                ans[j]=(int)unfinished;
            }
        }
        return ans;

        
    }
};