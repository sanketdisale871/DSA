class Solution {
    private:
    bool isPossible(int mid,vector<int>& houses, vector<int>& heaters){
        int i=0;
        int j = 0;

        while(i<houses.size() && j<heaters.size()){
            int mini = heaters[j]-mid;
            int maxi = heaters[j]+mid;

            if(houses[i]>=mini && houses[i]<=maxi){
                i++;
            }
            else{
                j++;
            }
        
        }
        return i>=houses.size();
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int low = 0;
        int high = INT_MAX;

        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,houses,heaters)){
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