class Solution {
public:
typedef long long int ll;
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<ll,ll>um;

        int m = wall.size();

        int sum = accumulate(wall[0].begin(),wall[0].end(),0);

        ll maxiCrack = 0;

        for(int i=0;i<m;i++){
            ll currSum = 0;

            for(int j=0;j<wall[i].size();j++){
                currSum+=wall[i][j];

                if(currSum==sum){
                    continue;
                }

                um[currSum]++;

                maxiCrack=max(maxiCrack,um[currSum]);
            }
        }

        return m-maxiCrack;

    }
};