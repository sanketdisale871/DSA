class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        string temp = "0000";
        unordered_set<string>vis;
        unordered_set<string>dea(deadends.begin(),deadends.end());
        vis.insert(temp);

        if(dea.count(temp)){
            return -1;
        }

        queue<pair<int,string>>q;
        q.push({0,temp});

        while(!q.empty()){
            auto it = q.front();q.pop();

            if(it.second == target){
                return it.first;
            }

            for(int i=0;i<4;i++){
                string t = it.second;
                char temp = t[i];

                t[i]= temp=='9'?'0':temp+1;

                if(vis.count(t)==0 && dea.count(t)==0){
                    vis.insert(t);
                    q.push({it.first+1,t});
                }

                t[i]= temp=='0'?'9':temp-1;

                if(vis.count(t)==0 && dea.count(t)==0){
                    vis.insert(t);
                    q.push({it.first+1,t});
                }

                t[i]=temp;
            }
        }

        return -1;
    }
};