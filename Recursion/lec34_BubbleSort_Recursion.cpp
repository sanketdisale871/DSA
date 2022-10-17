#include<bits/stdc++.h>

using namespace std;

void sortArray(int *arr,int n){
    // base case - jb array ka size one ya zero rehega to array is already sorted
    if(n==1 || n==0){
        return;
    }
    
    // ek case solve kardo
    for(int i=0;i<(n-1);i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    // baki recurssio kar lega
    
    return sortArray(arr,n-1);
}

int main(){
    
    int arr[]={
        12,10,15,11,18
    };
    
    int n = sizeof(arr)/sizeof(arr[0]);
   
    sortArray(arr,n);
    
    cout<<"Printing Array :\n";
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
