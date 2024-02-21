class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        // long long int sum = 0;
        // // pair<diff,amnt>
        // priority_queue<pair<int,int>>maxHeap;

        // int n = reward1.size();

        // for(int i=0;i<n;i++){
        //     maxHeap.push({reward1[i]-reward2[i],i});
        // }

        // while(k--){
        //     auto it=maxHeap.top();maxHeap.pop();
        //     int ind = it.second;
        //     sum+=(reward1[ind]);
        //     reward2[ind]=0;
        // }

        // for(int i=0;i<n;i++){
        //     sum+=(reward2[i]);
        // } 
        // return (int)sum;

        int n=r1.size();
        vector<pair<int,int>> dif(n);
        for (int i=0;i<n;i++)dif[i]={r1[i]-r2[i],i};
        sort(dif.rbegin(),dif.rend());
        int ans=0;
        for (int i=0;i<k;i++){
            ans+=r1[dif[i].second];
            r2[dif[i].second]=0;
        }
        for (int i:r2)ans+=i;
        return ans;
        
    }
};