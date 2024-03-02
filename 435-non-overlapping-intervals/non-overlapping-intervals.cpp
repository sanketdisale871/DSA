class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;

        sort(intervals.begin(),intervals.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });

        vector<int>temp = intervals[0];

        for(int i=1;i<intervals.size();i++){

            if(temp[1]<=intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]);
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};