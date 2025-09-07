class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;


    // pair<int,int> ,, pair<dist,pts
        priority_queue<pair<int,int>>maxHeap;

        for(auto it:arr){
            int dist = abs(it-x);
            maxHeap.push({dist,it});

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
      while(!maxHeap.empty()){
        auto it = maxHeap.top();maxHeap.pop();
        ans.push_back(it.second);
      }

        /*
        I have return the 'k' closet integers 
        */
        sort(ans.begin(),ans.end());
        return ans;
    }
};