class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pr, vector<int>& wrk) {
        vector<pair<int,int>>v;

        int n = diff.size();

        for(int i=0;i<n;i++){
            v.push_back({diff[i],pr[i]});
        }

        sort(v.begin(),v.end());

        sort(wrk.begin(),wrk.end());

        priority_queue<int>maxHeap;
        long long ans = 0;

        int i=0;
        for(auto it:wrk){
            // cout<<"IT : "<<it<<endl;
            while(i<n && v[i].first<=it){
                maxHeap.push(v[i].second);
                //  cout<<"v[i].second : "<<v[i].second<<endl;
                i++;
            }

            if(!maxHeap.empty()){
                ans+=maxHeap.top();
            }
        }
        return ans;
    }
};