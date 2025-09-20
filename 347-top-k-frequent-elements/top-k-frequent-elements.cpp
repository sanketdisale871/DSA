class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        K most frequent elements ke liye, 
        map will keep the track of frequency. 
        unordered_map<int,int>um;
        // return the 'k' most frequent elements. 
        --> FOR THAT, MIN_HEAP implementation will do, 
        and will remove the other elements. 
        el => freq
        1 => 3
        2 => 2
        3 => 1

        With the map will keep track the frequency; 

        */
        unordered_map<int,int>freq;
        for(auto it:nums){
            freq[it]++;
        }
        // Will have the freq,elem

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        
        for(auto it:freq){
            minHeap.push({it.second,it.first}); // freq,elem

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int>ans;

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};