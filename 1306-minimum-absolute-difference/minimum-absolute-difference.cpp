class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;

        sort(arr.begin(),arr.end());

        int minDiff = INT_MAX;

        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];

            if(diff<minDiff){
                ans.clear();
                minDiff = diff;
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(diff==minDiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};