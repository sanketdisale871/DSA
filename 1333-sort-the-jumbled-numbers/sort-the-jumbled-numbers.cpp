class Solution {
public:
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) {
        vector<pair<int,int>>ans;

        for(auto it:nums){
            int num = it;
            int mult = 1;
            int res =0;
            do{
                int dig = it%10;
                it/=10;
                res = res+map[dig]*mult;
                mult*=10;
                // res += to_string(map[dig]);
                // cout<<"dig : "<<dig<<" map[dig] : "<<map[dig]<<endl;
            }while(it);
            // reverse(res.begin(),res.end());
            cout<<"res : "<<res<<endl;
            ans.push_back({res,num});
        }

        sort(ans.begin(),ans.end(),[&](pair<int,int>a,pair<int,int>b){
            return a.first<b.first;
        });

        vector<int>temp;

        for(auto it:ans){
            temp.push_back(it.second);
        }

        return temp;
    }
};