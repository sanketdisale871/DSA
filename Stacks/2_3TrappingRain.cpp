class Solution {
public:
/*
    int trap(vector<int>& height) {
        /* Approach1 : => left and right end there is no wall
        => at any point we store water is :
           water[i]= min (max_left_height,max_right_height)-arr[i];
           
           Time Complexity : O (3n) -> Traversing loop two times
           Space Complexity : O(3n) -> Declaring two vector spaces

            
           int n = height.size();
           vector<int>lmax(n,0);
           vector<int>rmax(n,0);

           int lmaxi = 0;
           int rmaxi = 0;

           // contain left maximum element for each index element

           for(int i=0;i<n;i++){
               lmax[i]=lmaxi;
               lmaxi = max(lmaxi,height[i]);
           }
          // contain right maximum element for each index element
           for(int i=n-1;i>=0;i--){
               rmax[i]=rmaxi;
               rmaxi = max(rmaxi,height[i]);
           } 

           int cnt = 0;
           for(int i=0;i<n;i++){
               int res = min(lmax[i],rmax[i])-height[i];

               if(res>0){
                   cnt+=res;
               }
           }
           return cnt;
    }
    */

    /* Approach 2 : Two Pointer approach
            T.C = O(n)
            S.C = O(1)  
    */

    int trap(vector<int>& height){
        int n = height.size();
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = n-1;
        int res = 0;

        while(l<r){

            if(height[l]<=height[r]){
                if(height[l]>=lmax){
                    lmax = height[l];
                }
                else{
                    res+=(lmax - height[l]);
                }
                l++;
            }
            else{
                if(height[r]>=rmax){
                    rmax = height[r];
                }
                else{
                    res+=(rmax-height[r]);
                }
                r--;
            }
        }
        return res;

    }
};
