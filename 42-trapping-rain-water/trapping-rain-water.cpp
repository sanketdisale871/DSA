class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>left(n,0);
        vector<int>right(n,0);

        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);

            left[i]=maxi;
        }

        maxi = 0;
        // For right hand calculating maximum one
        for(int j=n-1;j>=0;j--){
                maxi = max(maxi,height[j]);
                right[j]=maxi;
        }

        // Calculating witer 
        int ans = 0;

        for(int i=0;i<n;i++){
            int currWtr = min(left[i],right[i])-height[i];

            ans+=currWtr;
        }

        return ans;
    }
};