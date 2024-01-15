class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;

        for(int i=0;i<matches.size();i++){
            mp[matches[i][0]]+=0;
            mp[matches[i][1]]++;
        }

        vector<vector<int>>ans(2);
        for(auto a: mp){
            if(a.second==0)ans[0].push_back(a.first);
            if(a.second==1)ans[1].push_back(a.first);
        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};
