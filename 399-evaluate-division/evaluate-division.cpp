class Solution {
    private:
    unordered_map<string,vector<pair<string,double>>>adjList;
    unordered_set<string>avlNodes;
    double qAns;

    void buildGraph(vector<vector<string>>& eq, vector<double>& vals){

            for(int i=0;i<eq.size();i++){
                string u = eq[i][0];
                string v = eq[i][1];
                double wt = vals[i];
                avlNodes.insert(u);
                avlNodes.insert(v);

                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,1.0/wt});
            }
    }

    void dfsCall(string u,string v,unordered_set<string>&vis,double recrProd){
        vis.insert(u);

        if(avlNodes.count(u)==0){
            return;
        }

        if(u==v){
            qAns = recrProd;
            return;
        }

        for(auto it:adjList[u]){
            string newU = it.first;
            double val = it.second;

            if(vis.count(newU)==0){
                dfsCall(newU,v,vis,recrProd*val);
            }
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int qSize = queries.size();
        vector<double>ans;
        buildGraph(equations,values);

        for(auto it:queries){
            string u = it[0];
            string v = it[1];

            if(avlNodes.count(u)==0 || avlNodes.count(v)==0){
                ans.push_back(-1.0);
            }
            else{
                qAns = -1.0;
                unordered_set<string>vis;
                dfsCall(u,v,vis,1);
                ans.push_back(qAns);
            }
        }


        return ans;
    }
};