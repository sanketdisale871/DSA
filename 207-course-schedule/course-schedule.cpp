class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        int topoElem = 0;
        vector<int>inde(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                inde[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inde[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node = q.front();q.pop();

            topoElem++;

            for(auto it:adj[node]){
                inde[it]--;
                if(inde[it]==0){
                    q.push(it);
                }
            }
        }

        return topoElem==numCourses;
    }
};