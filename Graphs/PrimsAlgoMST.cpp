#include<bits/stdc++.h>

using namespace std;

int main(){

    int N,m;
    cin>>N>>m;
    

    vector<pair<int,int>>adj[N];

    int node1,node2,weight;

    for(int i=0;i<m;i++){
        
        cin>>node1>>node2>>weight;

        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});
        
    }


    int parent[N];
    int key[N];
    bool mstSet[N];

    /* Intiallising arrays */

    for(int i=0;i<N;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mstSet[i]=false;
    }

    key[0]=0;
   
    // 1 has fixed key already 0 , hence we running cnt variable upto N-1 times
    for(int cnt = 0;cnt < N-1;cnt++){

        int mini = INT_MAX,u;

    /* Finging minimum number from key's and it's index */
        for(int v =0;v<N;v++){

            if(mstSet[v]==false && key[v]<mini){
                mini = key[v];
                u = v;
            }
        }

        mstSet[u]=true;

    /* Updating adjacent of u , with parent and MST arrays */
        for(auto it : adj[u]){
            int v = it.first;
            int wt = it.second;

            if(mstSet[v]==false && wt<key[v]){
                parent[v]=u;
                key[v]=wt;
            }
        }
    }

    /* Printing MST */

    for(int i=1;i<N;i++){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
   


    return 0;
}
