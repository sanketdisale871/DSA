#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

    private:
    vector<int>parent,size;

    public:

    /* intiallsing parent and size */

    DisjointSet(int n){
   
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    /* Finding ultimate parent */

    int findUltPar(int node){

        // base case 
        if(node == parent[node]){
            return node;
        }

        return parent[node]=findUltPar(parent[node]);
    }

    /* finding union by size */



    void unionBySize(int v,int u){
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }


};

int main(){

    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    // if 3 and 7 are belong to same parent or not

    if(ds.findUltPar(3)==ds.findUltPar(7)){
        cout<<"\nSame.";
    }else{
        cout<<"\nNot same.";
    }
    
    ds.unionBySize(3,7);
    cout<<"\nAfter one : ";
    if(ds.findUltPar(3)==ds.findUltPar(7)){
        cout<<"\nSame.";
    }else{
        cout<<"\nNot same.";
    }



    return 0;
}
