class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int lmax = 0;
        int rmax = 0;

        int i=0,j=n-1;

        while(i<=j){
            if(height[i]<=height[j]){
                lmax=max(lmax,height[i]);

                ans+=(lmax-height[i]);
                i++;
            }
            else{
                rmax=max(rmax,height[j]);

                ans+=(rmax-height[j]);
                j--;
            }
        }
        return ans;
    }
};