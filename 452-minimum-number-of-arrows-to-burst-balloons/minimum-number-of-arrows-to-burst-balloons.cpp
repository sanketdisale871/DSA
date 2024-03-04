class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });

        vector<int>temp = points[0];
        int cnt =1;

        int n = points.size();

        for(int i=1;i<n;i++){
            if(points[i][0]<=temp[1]){
                continue;
            }
            else{
                cnt++;
                temp = points[i];
            }
        }


        return cnt;
    }
};