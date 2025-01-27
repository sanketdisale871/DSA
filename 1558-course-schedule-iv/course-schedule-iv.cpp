class Solution {
    /*
    Approach:
    1) Num => Ind
    2) Traver Preq.
    */
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>indeg(numCourses,0);
        int n = numCourses;
        vector<unordered_set<int>>adj(n);

        unordered_map<int,unordered_set<int>>um;

        for(auto it:prerequisites){
            adj[it[0]].insert(it[1]);
            indeg[it[1]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){

       
            auto curr = q.front();q.pop();
        

            for(auto nex:adj[curr]){
                um[nex].insert(curr);
                for(auto ittt:um[curr]){
                    um[nex].insert(ittt);
                }
                indeg[nex]--;
                if(indeg[nex]==0){
                    q.push(nex);
                }
            }
          
        }   

    

        vector<bool>ans;

        for(auto it:queries){
            ans.push_back(um[it[1]].count(it[0]));
        }

        return ans;
    }
};