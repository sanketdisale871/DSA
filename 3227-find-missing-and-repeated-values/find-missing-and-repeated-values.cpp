class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();

        unordered_map<int,int>freq;

        int totNums = n*n;

        for(int i=1;i<=totNums;i++){
            freq[i]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]--;
            }
        }

        int a = 0;
        int b = 0;

        for(int i=1;i<=totNums;i++){
            if(freq[i]==-1){
                a = i;
            }

            if(freq[i]==1){
                b = i;
            }
        }

        return {a,b}; 
    }
};