class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());

        int ans = 0;
        int i=0;
        int j= i+1;
        int n = arr.size();
        while(i<n-1 && j<n){
            if(arr[i][1] >= arr[j][0]){
                arr[i][1] = min(arr[i][1],arr[j][1]);
                j++;
            }else{
                i = j;
                j = i+1;
                ans++;
            }
        }
        return ans+1;
    }
};