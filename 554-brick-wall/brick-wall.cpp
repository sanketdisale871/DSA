class Solution {
public:
typedef long long int ll;
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<ll,ll>um;

        int m = wall.size();

        ll maxiCrack = 0;

        for(int i=0;i<m;i++){
            ll crackDist = 0;

            for(int j=0;j<wall[i].size()-1;j++){ // Not traversing last brick

                crackDist+=wall[i][j];

                um[crackDist]++;

                maxiCrack=max(maxiCrack,um[crackDist]);
            }
        }

        return m-maxiCrack;

    }
};