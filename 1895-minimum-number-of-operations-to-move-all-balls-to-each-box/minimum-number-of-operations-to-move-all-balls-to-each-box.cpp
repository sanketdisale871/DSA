class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.size();
        vector<int>ans(n);

        vector<pair<int,int>>pref(n);
        int prefSum = 0;
        int oneCnt = 0;

        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                prefSum+=i;
                oneCnt++;
            }
            pref[i]={prefSum,oneCnt};
        }   
        
        for(int i=0;i<n;i++){
            int lef = i-1;
            int rig = i+1;

            int cnt = 0;

            if(lef>=0){
                int res = (i*pref[lef].second) - pref[lef].first;
                cnt+=res;
            }

            if(rig<n){
                int res = (pref[n-1].first-pref[i].first) - ((pref[n-1].second-pref[i].second)*i);
                cnt+=res;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};