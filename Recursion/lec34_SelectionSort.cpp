#include<bits/stdc++.h>

using namespace std;

/
/* Slection Sort */

void sortArray(int *arr,int n,int i){
    
    // Base condition - 
    
    if(i == (n-1)){
        return;
    }
    
    // ek case solve kar do
    
    for(int j=(i+1);j<n;j++){
        if(arr[i]>arr[j]){
            // cout<<"in condtion :  arr[i] -> "<<arr[i]<<" arr[j] -> "<<arr[j]<<endl;
        swap(arr[i],arr[j]);
        }
// cout<<"out condtion :  arr[i] -> "<<arr[i]<<" arr[j] -> "<<arr[j]<<endl;

    }
    i++;
    
    // baki ka recursion dekh lega
    return sortArray(arr,n,i);
    
}

int main(){
    int n;cin>>n;
    
    int *arr = new int[n];
    
for(int i=0;i<n;i++){
cin>>arr[i];
}

    sortArray(arr,n,0);
    
    cout<<"Printing Array :\n";
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
