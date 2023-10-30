class Solution {
    private:
    int cntOnes(int n){
        int one = 0;

        while(n){
            if((n & (1<<0))){
                one++;
            }
            n>>=1;
        }
        return one;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;

        unordered_map<int,int>um;

        for(auto it : arr){
            if(um.find(it)==um.end()){
                um[it]=cntOnes(it);
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(auto num : arr){
            minHeap.push({um[num],num});
        }

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }


        return ans;
    }
};