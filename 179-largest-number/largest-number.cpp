class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;

        for(auto it:nums){
            arr.push_back(to_string(it));
        }

        sort(arr.begin(),arr.end(),[&](string a,string b){
            return a+b>b+a;
        });
        string ans;
        for(auto it:arr){
            ans+=it;
        }

        while(ans.length()>1 && ans[0]=='0'){
            ans.erase(0,1);
        }
        return ans;
    }
};