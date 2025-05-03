class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // Approach: 
        // 1) TOP pe sabhi try karlo, 1-6 => Take the minimum from all of them 
        // 2) Bottom pe sabhi try karlo, 1-6 => Take minimum from all of them
        int ans = INT_MAX;
        int n = tops.size();
        
        for(int topNum=1;topNum<=6;topNum++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(tops[i]==topNum){
                    continue;
              }

              if(bottoms[i]==topNum){
                cnt++;
              }
              else{
                cnt = INT_MAX;
                break;
              }
            }
            ans = min(ans,cnt);
        }

        // Bottom wala karate hai 
        for(int btmNum=1;btmNum<=6;btmNum++){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(bottoms[i]==btmNum){
                    continue;
              }

              if(tops[i]==btmNum){
                cnt++;
              }
              else{
                cnt = INT_MAX;
                break;
              }
            }
            ans = min(ans,cnt);
        }
        return ans==INT_MAX?-1:ans;
    }
};