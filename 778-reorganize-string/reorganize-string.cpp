class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<int,int>um;
        // maxHeap<freq,char>
        priority_queue<pair<int,char>>maxHeap;
        for(auto it:s){
            um[it]++;
        }

        for(auto it:um){
            maxHeap.push({it.second,it.first});
        }

        while(maxHeap.size()>1){
            auto it1 = maxHeap.top();maxHeap.pop();
            auto it2 = maxHeap.top();maxHeap.pop();

            // cout<<"it1 char : "<<it1.second<<" freq: "<<it1.first<<endl;
            // cout<<"it2 char : "<<it2.second<<" freq: "<<it2.first<<endl;
    
            ans.push_back(it1.second);
            if(it1.first-1>0){
                maxHeap.push({it1.first-1,it1.second});
            }

            ans.push_back(it2.second);
            if(it2.first-1>0){
                maxHeap.push({it2.first-1,it2.second});
            }
        }

        if(!maxHeap.empty() && maxHeap.top().first>1){
            return "";
        }
        else if(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
        }
        return ans;
    }
};