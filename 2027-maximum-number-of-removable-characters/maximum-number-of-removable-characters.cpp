class Solution {
    private:
    bool isPossible(int mid,string &s,string &p,vector<int>&remo){

        vector<int>isRemo(100001,0);

        for(int i=0;i<=mid;i++){
            isRemo[remo[i]]=1;
        }

        int i=0,j=0;

        while(i<s.length() && j<p.length()){
            if(isRemo[i]){
                i++;
                continue;
            }

            if(s[i]==p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(j==p.length()){
            return true;
        }

        return false;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& remo) {
        int low = 0;
        int high = remo.size()-1;

        int ans = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,s,p,remo)){
                ans = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};