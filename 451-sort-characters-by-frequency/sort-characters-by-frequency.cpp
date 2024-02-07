class Solution {
public:
    string frequencySort(string s) {
        string str ="";
        unordered_map<char,int>um;
        priority_queue<pair<int,char>>maxHeap;

        for(auto ch:s){
            um[ch]++;
        }

        for(auto it:um){
            maxHeap.push({it.second,it.first});
        }

        while(!maxHeap.empty()){
            int freq = maxHeap.top().first;
            auto ch =  maxHeap.top().second;

            while(freq--){
                str.push_back(ch);

            }
           
            maxHeap.pop();
        }
        return str;
    }
};