class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans(votes[0]);
        int n = votes[0].length();

        vector<vector<int>>ranks(26,vector<int>(n));

        for(auto &vote:votes){
            for(int i=0;i<n;i++){
                ranks[vote[i]-'A'][i]++;
            }
        }

        sort(ans.begin(),ans.end(),[&](char x, char y){
            if(ranks[x-'A']==ranks[y-'A']){
                return x<y;
            }
            else{
                return ranks[x-'A']>ranks[y-'A'];
            }
        });
        return ans;
    }
};