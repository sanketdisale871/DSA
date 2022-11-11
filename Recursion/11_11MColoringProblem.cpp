//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isSafe(int color,int node,int m,int col[],bool graph[101][101]){
        
        // checking each node
        for(int i=0;i<node;i++){
            
            if(i!=node && graph[i][node]==1 && col[i]==color){
                return false;
            }
        }
        return true;
    }

    bool solve(int node,int n, int m,int col[],bool graph[101][101]){
        
        // Base case
        
        if(node==n){
            return true;
        }
        
        for(int k=1;k<=m;k++){
            
            if(isSafe(k,node,m,col,graph)){
                col[node]=k;
                
                bool aageSol = solve(node+1,n,m,col,graph);
                
                if(aageSol){
                    return true;
                }else{
                    // backtracking
                    col[node]=0;
                }
            }
        }
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
       
       int col[n]={0};
       
       if(solve(0,n,m,col,graph)){
           return true;
       }else{
           return false;
       }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
