#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int row,col;
    cin>>row>>col;
    
    int **arr = new int*[row];
    
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    
    /*Taking input in array */
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    
        /*Taking Output in array */
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    
    delete []arr ;
    
    return 0;
}
