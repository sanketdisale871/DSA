class Solution {
public:
    int n = 1e4+100;
    int minimumOperationsToMakeEqual(int x, int y) {
        

        // I have to reach x----> y , SRC = x and DEST = y 

        vector<int>dist(n,1e9);

        // pair<int,int> == pair<cost,node>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        dist[x]=0;
        minHeap.push({0,x});

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            int node = it.second;
            int cost = it.first;

            if(node%11 == 0 && dist[node]+1<dist[node/11]){
                dist[node/11]=1+dist[node];
                minHeap.push({dist[node/11],node/11});
            }

            if(node%5 == 0 && dist[node]+1<dist[node/5]){
                dist[node/5]=1+dist[node];
                minHeap.push({dist[node/5],node/5});
            }

            if(node>0 && dist[node]+1<dist[node-1]){
                dist[node-1]=1+dist[node];
                minHeap.push({dist[node-1],node-1});
            }

            if(node+1 <n && dist[node]+1<dist[node+1]){
                dist[node+1]=dist[node]+1;
                minHeap.push({dist[node+1],node+1});
            }
        }

        for(int i=y;i<=x;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;

        return dist[y];
    }
};