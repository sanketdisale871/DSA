class Solution {
    bool isPossible(int days,vector<int>& bloomDay, int m, int k){
        int mdBqt = 0;
        int adj=k;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                adj--;

                if(adj==0){
                    mdBqt++;

                    adj = k;
                }
            }
            else{
                adj = k;
            }
        }
        return mdBqt>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};