class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        // pair<temp,ind)
        stack<pair<int,int>>st;

        int n = temp.size();
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--){
            int dist = 0;

            while(!st.empty() && temp[i]>= st.top().first){
                st.pop();
            }

            if(!st.empty()){
               dist = st.top().second - i;
            }
            
            ans[i]=dist;
            st.push({temp[i],i});
        }
        return ans;
    }
};