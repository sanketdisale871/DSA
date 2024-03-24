class Solution {
public:
    typedef long long int ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll>ans;


        unordered_map<ll,ll>um; // um<num,freq>
        // pair<freq,num>
        set<pair<ll,ll>,greater<pair<ll,ll>>>st;

        for(ll i=0;i<nums.size();i++){

            auto it = st.find({um[nums[i]],nums[i]});

            if(it!=st.end()){
                st.erase(it);
            }

            um[nums[i]]+=freq[i];

            st.insert({um[nums[i]],nums[i]});


            // finding top element 
            auto itt = st.begin();
            auto p = *itt;

            ans.push_back(p.first);
        }


        return ans;
    }
};