class Solution {
public:
    typedef int ll;
    int minimumDistance(vector<vector<int>>& a) {
        ll n = a.size();

        multiset<ll>st;
        multiset<ll>st2;

        for(auto it:a){
            st.insert(it[0]+it[1]);
            st2.insert(it[0]-it[1]);
        }

        ll ans = INT_MAX;


        // for(int i=0;i<n;i++){
        //     st.erase(st.find(a[i][0]+a[i][1]));
        //     st2.erase(st2.find(a[i][0]-a[i][1]));
        //     int sum=max(*(prev(st.end()))-*(st.begin()),*(prev(st2.end()))-*(st2.begin()));
        //     ans=min(ans,sum);
        //     st.insert(a[i][0]+a[i][1]);
        //     st2.insert(a[i][0]-a[i][1]);
        // }

        for(auto it:a){
            
            st.erase(st.find(it[0]+it[1]));
            st2.erase(st2.find(it[0]-it[1]));

            // int res1 = *(prev(st.end()))-*(st.begin());
            // int res2 = *(prev(st2.end()))-*(st2.begin());

            int res = max(*(prev(st.end()))-*(st.begin()),*(prev(st2.end()))-*(st2.begin()));

            ans = min(ans,res);

            st.insert(it[0]+it[1]);
            st2.insert(it[0]-it[1]);
            
        }



        return ans;
    }
};