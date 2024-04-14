#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // Less Than equal to Order

class Solution {
public:
    typedef long long int ll;
    long long numberOfSubarrays(vector<int>& nums) {
        // pbds Pb;

        ll n = nums.size();

        vector<ll>lefInd(n,-1);

        stack<ll>st;
        st.push(-1);

        for(ll i=0;i<nums.size();i++){
            while(st.top()!=-1 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            lefInd[i]=st.top();
            st.push(i);
        }

        ll cnt = 0;

        unordered_map<ll,pbds>um;

        for(int i=0;i<n;i++){
            int el = nums[i];
            int nextLargInd = lefInd[i];

            int res = um[el].size()-um[el].order_of_key(nextLargInd);

            cnt+=res+1;

            um[el].insert(i);
        }
        


        return cnt;
    }
};