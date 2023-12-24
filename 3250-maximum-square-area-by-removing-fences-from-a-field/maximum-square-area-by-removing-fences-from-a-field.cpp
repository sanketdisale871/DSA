class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        int mod=1e9+7;
        unordered_set<int>s1,s2;
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        for(int i=0;i<h.size();i++) {
            for(int j=i+1;j<h.size();j++) {
                s1.insert(h[j]-h[i]);
            }
        }
        for(int i=0;i<v.size();i++) {
            for(int j=i+1;j<v.size();j++) {
                s2.insert(v[j]-v[i]);
            }
        }
        long long ans=0;
        for(auto i:s1) {
            if(s2.find(i)!=s2.end()) {
                long long k=(long long)i*i;
                if(k>ans)
                    ans=k;
            } 
        }
        if(ans==0)
            return -1;
        ans=ans%mod;
        return ans;
    }
};