class Solution {
public:
// Approach L Using Heap
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans(k);

        int n = arr.size();

        priority_queue<pair<int,int>>maxHeap;

        for(int i=0;i<n;i++){
            maxHeap.push({abs(x-arr[i]),arr[i]});

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        for(int i=k-1;i>=0;i--){
            ans[i]=maxHeap.top().second;
            maxHeap.pop();
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};
