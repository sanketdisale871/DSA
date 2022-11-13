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
    
    
    
    /// printing speciffic row of pascals triangle
    
    class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>ans;
        
        int i = rowIndex;
        int value = 1;
        
        for(int j=0;j<=i;j++){
            ans.push_back(value);
            value=value*1LL*(i-j) / (j+1) ;
        }
        return ans;
    }
};
    
    
  // printing speciffic element of given row and column
    
    #include<bits/stdc++.h>

using namespace std;

int main(){
    
    int row =4;
    int col = 3;
    
    int i = row-1;
    int j = col -1;
    
    int val = 1;
    
    for(int jj=0;jj<j;jj++){
        
        val = val * (i-jj) / (jj+1) ;
    }
    
    cout<<val<<endl;
    
    return 0;
}
    
    
    
   
    
    return 0;
}
