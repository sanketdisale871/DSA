class Solution {
    /*\
    i ke aage favorite[i] chahiye. 

    Think: 
    1) One node have two next places, means,         node
                                                 em1       em2
    Cases: 

    1) Cycle of length 2,   Suppose, node1 and node2, node1 have 1 empty position, let's try ki, 
    one more maximum wali branch that position, and node2 have 1 empty position, let's try ki one more
    maximum wali branch that positon


    2) Cycle of length>2, All node are occupies, in cycle. So, we have to only cosider the Length of cycle. 

    Approach:
    1) For each node ke liye find the depth, => Helpfull, when length 2.
    2) Otherwise, length>2, consider that length.   
    */
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int>indeg(n,0),depth(n,1);

        for(int person=0;person<n;person++){
            indeg[favorite[person]]++;
        }

        queue<int>q;

        for(int person=0;person<n;person++){
            if(indeg[person]==0){
                q.push(person);
            }
        }

        while(!q.empty()){
            auto node = q.front();q.pop();

            int nex = favorite[node];

            depth[nex]=max(depth[nex],1+depth[node]);

            indeg[nex]--;

            if(indeg[nex]==0){
                q.push(nex);
            }
        }

        int twoCycleInvi = 0;
        int longCycle = 0;

        for(int person=0;person<n;person++){
            if(indeg[person]==0){
                continue;
            }

            int cyclLen = 0;
            int curr = person;

            while(indeg[curr]!=0){
                indeg[curr]=0;
                cyclLen++;
                curr = favorite[curr];
            }

            if(cyclLen==2){
                twoCycleInvi+=depth[person]+depth[favorite[person]];
            }
            else{
                longCycle = max(longCycle,cyclLen);
            }
        }
        return max(longCycle,twoCycleInvi);

    }
};