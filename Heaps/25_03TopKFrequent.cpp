class Solution {
    // DSA Student : Sanket Disale
public:
/*Approach : 
    1) Store the elemt and it's count in unordered_map
    2) Min Heap will store the elem of Most Freq Elements
    3) After that traverse heap and push this count into the answer
*/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
       
        unordered_map<int,int>um;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }

        for(auto it : um){
            int ele = it.first;
            int freq = it.second;

            minHeap.push({freq,ele});

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
