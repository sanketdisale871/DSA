class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(),arr.end());

        int minDff = INT_MAX;

        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];

            if(diff<minDff){
                minDff = diff;
                ans.clear();

                ans.push_back({arr[i-1],arr[i]});
            }
            else if(diff==minDff){
                ans.push_back({arr[i-1],arr[i]});
            }

        }
        return ans;
    }
};