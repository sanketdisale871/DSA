class Solution {
public:
    typedef long long int ll;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9+7;

        vector<int>lefContr(n,0);
        vector<int>rigContr(n,0);

        // pair<num,int>
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            int x = 0;

            while(!st.empty() && st.top().first >= arr[i]){
                x++;
                x+=st.top().second;st.pop();
            }

            st.push({arr[i],x});
            lefContr[i]=x;
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            int x = 0;

            while(!st.empty() && st.top().first >arr[i]){
                x++;
                x+=st.top().second;

                st.pop();
            }
            st.push({arr[i],x});

            rigContr[i]=x;
        }

        ll tot = 0;

        for(ll i=0;i<n;i++){
            tot+=(lefContr[i]+1)*1ll*(rigContr[i]+1)*1ll*arr[i];
            tot%=mod;
        }
        return (int)tot;
    }
};