#include<bits/stdc++.h>

using namespace std;

vector<int>ans;

void prepareAdja(unordered_map<int,set<int>> &adjacancy,vector<pair<int,int>>&edges){

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjacancy[u].insert(v);
        adjacancy[v].insert(u);
    }
}

void bfs(int node,unordered_map<int,set<int>> &adjacancy,vector<int> &visited){

    ans.push_back(node);

    visited[node]=1;

    for(auto it : adjacancy[node]){
        if(!visited[it]){
            bfs(it,adjacancy,visited);
        }
    }


}

void dfsTraversal(vector<pair<int,int>>&edges,int v){

    // Preparing adjacancy list
    unordered_map<int,set<int>>adjacancy;

    vector<int>visited(v,0);

    prepareAdja(adjacancy,edges);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(i,adjacancy,visited);
        }
    }
}

int main(){

    int v,e;
    cout<<"Enter number of vertex and edges : \n";
    cin>>v>>e;

    cout<<"\nEnter the pair of edges :\n";

    vector<pair<int,int>>pairs;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        pairs.push_back({u,v});
    }

    dfsTraversal(pairs,v);

    cout<<"\nPrinting the dfs traversal : \n";

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;



    return 0;
}
