class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int>ans;

        unordered_map<int,int>um;
        int n = a.size();

        for(int i=0;i<n;i++){
            um[a[i]]++;
            int cnt = 0;

            for(int j=i;j>=0;j--){
                if(um[b[j]]!=0){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }


        return ans;
    }
};