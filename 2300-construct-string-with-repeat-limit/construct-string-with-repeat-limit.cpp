class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>maxHeap;

        string str = "";

        unordered_map<char,int>um;

        for(auto it:s){
            um[it]++;
        }

        for(auto it:um){
            maxHeap.push({it.first,it.second});
        }

        char prevChar = '8';
        while(!maxHeap.empty()){
            auto it = maxHeap.top();maxHeap.pop();

            if(it.first!=prevChar){
                int cnt = min(it.second,repeatLimit);
                  int t = cnt;
                while(cnt--){
                    str.push_back(it.first);
                }

                if(it.second-t>0){
                    maxHeap.push({it.first,it.second-t});
                }

                prevChar = it.first;

            }
            else{
                if(maxHeap.empty()){
                    break;
                }
                auto it1 = maxHeap.top();maxHeap.pop(); maxHeap.push(it);


                int cnt = min(1,repeatLimit);
                int t = cnt;
                while(cnt--){
                    str.push_back(it1.first);
                }

                if(it1.second-t>0){
                    maxHeap.push({it1.first,it1.second-t});
                }

                prevChar = it1.first;
            }
        }
        return str;
    }
};