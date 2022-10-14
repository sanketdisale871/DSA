#include<bits/stdc++.h>

using namespace std;

bool isSortted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool ans = isSortted(arr+1,size-1);
    return ans;
}

int main(){
    
    int n;cin>>n;
    int *arr;
    arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
   if(isSortted(arr,n)==false){
       cout<<"\nGiven array is not sortted.\n";
   }
   else{
       cout<<"\nGiven array is sortted.\n";
   }
    
    return 0;
}
