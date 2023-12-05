class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int,int>um;
        unordered_map<int,int>vis;

        for(auto num : nums){
            um[num]++;
        }

        for(auto num : nums){
            int x = num;
            int y = k-num;

            if(vis[x]==0 && vis[y]==0){
                if(x==y){
                    cnt+=(um[x]/2);
                }
                else{
                    cnt+=min(um[x],um[y]);
                }
            }

            vis[x]=1;
            vis[y]=1;
        }
        return cnt;
    }
};