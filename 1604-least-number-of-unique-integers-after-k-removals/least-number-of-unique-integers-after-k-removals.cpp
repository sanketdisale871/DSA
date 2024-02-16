class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>um;

        for(auto it:arr){
            um[it]++;
        }

        
        priority_queue<pair<int,int>>maxHeap;

        for(auto it:um){
            int elm = it.first;
            int freq = it.second;

            maxHeap.push({-freq,elm});
        }
        
        while(!maxHeap.empty()){
            auto it = maxHeap.top();

            int freq = -it.first;

            if(freq<=k){
                maxHeap.pop();
                k-=freq;
            }
            else{
                return maxHeap.size();
            }
        }

        return 0;


    }
};