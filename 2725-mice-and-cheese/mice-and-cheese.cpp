class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        long long int sum = 0;
        // pair<diff,amnt>
        priority_queue<pair<int,int>>maxHeap;

        int n = reward1.size();

        for(int i=0;i<n;i++){
            maxHeap.push({reward1[i]-reward2[i],i});
        }

        while(k--){
            auto it=maxHeap.top();maxHeap.pop();
            int ind = it.second;
            sum+=(reward1[ind]);
            reward2[ind]=0;
        }

        for(int i=0;i<n;i++){
            sum+=(reward2[i]);
        } 
        return (int)sum;

        
        
    }
};