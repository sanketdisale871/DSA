class Solution {
    private:
    typedef long long int ll;

    bool isFeasible(const vector<int>& start, ll d, ll n, ll x) {
    
    ll last_chosen = start[0]; 

    

    for (int i = 1; i < n; ++i) {
       
        if (last_chosen + x > start[i] + d) {
            return false;  
        }

       
        last_chosen = max(start[i]*1ll, last_chosen + x);
    }
    
    return true;
}
public:
    int maxPossibleScore(vector<int>& start, int d) {
         ll n = start.size();
    
       
        sort(start.begin(), start.end());
        
      
        ll low = 0, high = start[n-1]+d - start[0], best_score = 0;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            if (isFeasible(start, d, n, mid)) {
                best_score = mid; 
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        
        return best_score;
        }
};