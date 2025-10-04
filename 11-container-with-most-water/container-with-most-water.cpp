class Solution {
public:
    int maxArea(vector<int>& ht) {
        int i = 0;
        int n = ht.size();
        int j = n-1;

        int maxArea = 0;


        while(i<j){
            int reHt = min(ht[i],ht[j]);
            int wtt  = j-i;
            int resAr = reHt*wtt;
            maxArea = max(maxArea,resAr);

            if(ht[i]>ht[j]){
                j--;
            }
            else{
                i++;
            }

        }
        return maxArea;
    }
};