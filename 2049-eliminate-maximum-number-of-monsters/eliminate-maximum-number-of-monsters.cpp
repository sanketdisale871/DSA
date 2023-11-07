class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>time;

        for(int i=0;i<n;i++){
            int t = (int) ceil(dist[i]/(speed[i]*1.0));
            time.push_back(t);
        }

        sort(time.begin(),time.end());

        for(int i=0;i<n;i++){
            if(i>=time[i]){
                return i;
            }
        }
        return n;
    }
};