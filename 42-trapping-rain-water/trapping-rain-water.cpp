class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>lefMaxi(n,0);
        vector<int>rigMaxi(n,0);

        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);

            lefMaxi[i]=maxi;
        }

        maxi = 0;

        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);

            rigMaxi[i]=max(rigMaxi[i],maxi);
        }

        int ar = 0;

        for(int i=0;i<n;i++){
            int res = min(lefMaxi[i],rigMaxi[i])-height[i];

            if(res>0){
                ar+=res;
            }
        }
        return ar;
    }
};