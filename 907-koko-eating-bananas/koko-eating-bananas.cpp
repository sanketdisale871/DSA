class Solution {
    private:
    bool isPossible(vector<int>& piles,int k, long long &h){
        long long rqHr = 0;

        for(int i=0;i<piles.size();i++){
            if(piles[i]%k !=0){
                rqHr+=(piles[i]/k) + 1;
            }
            else{
                rqHr+=piles[i]/k;
            }
            
        }
        cout<<"k : "<<k<<"Hr :"<<rqHr<<endl;
        return rqHr<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, long long h) {
        int n = piles.size();
        if(n>h){
            return -1;
        }

        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        cout<<high<<endl;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(piles,mid,h)){
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