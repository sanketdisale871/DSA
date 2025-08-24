class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lmaxi(n+1,0);
        vector<int>rmaxi(n+1,0);

        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            lmaxi[i]=maxi;
        }

        maxi = INT_MIN;

        for(int j=n-1;j>=0;j--){
            maxi = max(maxi,height[j]);
            rmaxi[j]=maxi;
        }
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int waterSt = min(lmaxi[i],rmaxi[i])-height[i];
            ans+=waterSt;
        }
        return ans;
    }
};