class Solution {
    private:
    vector<int>calOrderOfCourses(int numCourses,vector<vector<int>>&adj){
        vector<int>coursesOrder;

        vector<int>indeg(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>crsOrd;

        for(int crsItr=0;crsItr<numCourses;crsItr++){
            if(indeg[crsItr]==0){
                crsOrd.push(crsItr);
            }
        }

        while(!crsOrd.empty()){
            auto crs = crsOrd.front();crsOrd.pop();
            coursesOrder.push_back(crs);

            for(auto it:adj[crs]){
                indeg[it]--;
                if(indeg[it]==0){
                    crsOrd.push(it);
                }
            }
        }
        if(coursesOrder.size()==numCourses){
            return coursesOrder;
        }
        else{
            return {};
        }
    }
public:
// ai -> bi
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        // 0->1
        // [[1,0],[2,0],[3,1],[3,2]]

        // 1-> 0 , 2->0 , 3->1 , 3-> 2
        // indegree 
        // 0 1 2 3
        // 2 0 0 0

        vector<int>indeg(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());

        for(auto it:preq){
            adj[it[1]].push_back(it[0]);
        }


        return calOrderOfCourses(numCourses,adj);
    }
};