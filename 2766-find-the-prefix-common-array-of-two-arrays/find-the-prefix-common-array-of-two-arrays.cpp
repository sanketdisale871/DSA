class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int>ans;

        unordered_map<int,int>um;
        int n = a.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            um[a[i]]++;

            if(um[a[i]]==2){
                cnt++;
            }

            um[b[i]]++;

            if(um[b[i]]==2){
                cnt++;
            }
            ans.push_back(cnt);
        }


        return ans;
    }
};