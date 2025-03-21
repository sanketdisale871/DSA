class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recps, vector<vector<string>>& ingrds, vector<string>& supls) {
        vector<string>ans;

        unordered_set<string>spl;

        for(auto it:supls){
            spl.insert(it);
        }

        unordered_map<string,vector<string>>grph;

        unordered_map<string,int>indegree;

        for(auto it:recps){
            indegree[it]=0;
        }

        for(int i=0;i<ingrds.size();i++){
            for(int j=0;j<ingrds[i].size();j++){
                if(spl.count(ingrds[i][j])==0){
                    grph[ingrds[i][j]].push_back(recps[i]);
                    indegree[recps[i]]++;
                }
            }
        }

        queue<string>q;
        
        for(auto it:indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }

        while(!q.empty())
        {
            auto it = q.front();q.pop();
            ans.push_back(it);

            for(auto itt:grph[it]){
                indegree[itt]--;

                if(indegree[itt]==0){
                    q.push(itt);
                }
            }
        }

        return ans;
    }
};