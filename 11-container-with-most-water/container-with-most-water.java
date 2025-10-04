class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length-1;

        int maxWtr = -1;
        
        while(i<j){
            int ht = Math.min(height[i],height[j]);
            int br = j-i;

            int currAr = ht*br;

            maxWtr = Math.max(maxWtr,currAr);

            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxWtr;
    }
}