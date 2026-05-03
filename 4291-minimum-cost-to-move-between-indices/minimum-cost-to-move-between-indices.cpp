class Solution {
public:
    typedef long long int ll;
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>closeInd(n);
        vector<ll>forwrdCst(n,0);
        vector<ll>backCst(n,0);
        vector<int>ans;

        // closeInd[0]=1;

        for(int i=0;i<n;i++){
            if(i==0){
                closeInd[i]=1;
            }
            else if(i==n-1){
                closeInd[i]=n-2;
            }
            else{
                int lef = abs(nums[i]-nums[i-1]);
                int rig = abs(nums[i]-nums[i+1]);

                if(lef<=rig){
                    closeInd[i]=i-1;
                }
                else{
                    closeInd[i]=i+1;
                }
            }
        }

        for(int i=1;i<n;i++){
            if(closeInd[i-1]==i){
                forwrdCst[i]=1+forwrdCst[i-1];
            }
            else{
                forwrdCst[i] = forwrdCst[i-1] + abs(nums[i]-nums[i-1]);
            }
        }

        // Backward cst 
        for(int i=n-2;i>=0;i--){
            if(closeInd[i+1]==i){
                backCst[i]=1+backCst[i+1];
            }
            else{
                backCst[i]=backCst[i+1]+ abs(nums[i]-nums[i+1]);
            }
        }

        for(auto it:queries){
            int l = it[0];
            int r = it[1];

            if(l<=r){
                int cst = forwrdCst[r]-forwrdCst[l];
                ans.push_back(cst);
            }
            else{
                int cst = backCst[r]-backCst[l];
                ans.push_back(cst);
            }
        }
        return ans;
        
        
    }
};