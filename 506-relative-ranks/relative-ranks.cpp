class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>maxHeap;

        int n = score.size();
        vector<string>ans(n);

        for(int i=0;i<n;i++){
            maxHeap.push({score[i],i});
        }

        int rank = 1;

        while(!maxHeap.empty()){
            auto it = maxHeap.top();maxHeap.pop();

            if(rank==1){
                ans[it.second]="Gold Medal";
            }
            else if(rank==2){
                ans[it.second]="Silver Medal";
            }
            else if(rank==3){
                ans[it.second]="Bronze Medal";
            }
            else{
                ans[it.second]=to_string(rank);
            }
            rank++;
        }


        return ans;
    }
};