class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        priority_queue<int>maxHeap;
        unordered_map<char,int>um;

        for(auto it:tasks){
            um[it]++;
        }

        for(auto it:um){
            maxHeap.push(it.second);
        }

        int ans = 0;

        while(!maxHeap.empty()){

            vector<int>temp;

            for(int i=0;i<=k;i++){
                if(!maxHeap.empty()){
                    temp.push_back(maxHeap.top()-1);
                    maxHeap.pop();
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    maxHeap.push(temp[i]);
                }
            }
            
            ans+=maxHeap.empty()?temp.size():(k+1);
        }
        return ans;
    }
};