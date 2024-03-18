class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });

        int cnt = 1;
        vector<int> temp = points[0];

        for(int i=1;i<points.size();i++){
            if(points[i][0] <= temp[1]){
                continue;
            }
            else{
                temp = points[i];
                cnt++;
            }
        }
        return cnt;
    }
};