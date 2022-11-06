#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int rows ;
    cin>>rows;
    
    vector<vector<int>>pascleTrian(rows);
    
    
    ///printing pascles triangle
    
    for(int i=0;i<rows;i++){
        // element in that row
        pascleTrian[i].resize(i+1);
        // starting and ending with 1
        pascleTrian[i][0] = pascleTrian[i][i]=1;
        
        for(int j =1;j<i;j++){
            pascleTrian[i][j] = pascleTrian[i-1][j-1] + pascleTrian[i-1][j];
        }
    
    }
    
    cout<<"Printing Pascales triangle : "<<endl;
    
    for(auto &it : pascleTrian){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }cout<<endl;
    }
    
    
    
    return 0;
}
