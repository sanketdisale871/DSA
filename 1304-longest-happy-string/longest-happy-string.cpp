class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;

        // pair<int,char>
        priority_queue<pair<int,char>>maxHeap;

         if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        while(!maxHeap.empty()){
            auto[cnt1,char1]=maxHeap.top();
            maxHeap.pop();;

            if(ans.size()>1 && ans.back()==char1 && ans[ans.size()-2]==char1){
                if(maxHeap.empty()){
                    break;
                }
                auto[cnt2,char2]=maxHeap.top();
                maxHeap.pop();
                ans.push_back(char2);

                if(cnt2-1>0){
                    maxHeap.push({cnt2-1,char2});
                }

                maxHeap.push({cnt1,char1});
            }
            else{
                ans.push_back(char1);
               
                if(cnt1-1>0){
                    maxHeap.push({cnt1-1,char1});
                }
            }
        }
        return ans;
    }
};