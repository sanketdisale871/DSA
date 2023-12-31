class Solution {
public:
    typedef long long int ll;

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // If diff is less than 100 then these time is with the range of 1 hour.
//Example : (0549 - 0532) < 100 so 0549 and 0432 these time are within 1 hour and also these times ////(0636 - 0549) < 100.
        
        vector<string>ans;
        unordered_map<string,vector<ll>>um;

        for(auto it : access_times){
            um[it[0]].push_back(stoi(it[1]));
        }

        for(auto it:um){
            vector<ll>arr = it.second;

            sort(arr.begin(),arr.end());

            for(int i=2;i<arr.size();i++){
                if(arr[i]-arr[i-2]<100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }


        return ans;
    }
};