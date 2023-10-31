class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans=pref;

        for(int i=pref.size()-1;i>0;i--){
           ans[i]=pref[i-1]^pref[i];
        }

        return ans;
    }
};