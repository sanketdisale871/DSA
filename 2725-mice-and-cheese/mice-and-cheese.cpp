class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        long long int sum = 0;
        // pair<diff,amnt>
        priority_queue<pair<int,int>>maxHeap;

        unordered_set<int>userInd;

        int n = reward1.size();

        for(int i=0;i<n;i++){
            maxHeap.push({reward1[i]-reward2[i],i});
        }

        while(k--){
            auto it=maxHeap.top();maxHeap.pop();
            int ind = it.second;

            sum+=(reward1[ind]);
            userInd.insert(ind);
        }

        for(int i=0;i<n;i++){
            if(userInd.count(i)==0){
                sum+=(reward2[i]);
            }
        }

        return (int)sum;
    }
};