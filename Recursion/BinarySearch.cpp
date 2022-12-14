
#include<bits/stdc++.h>

using namespace std;

void print(int *arr,int s,int e){
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}


bool BinarySearch(int *arr,int s,int e,int k){
    
   
    print(arr,s,e);
    
    // Base Condition
    
    if(s>e){
        return false;
    }
    
    int mid = s + (e-s)/2 ;
    
    cout<<"Value of mid is : "<<arr[mid]<<endl;
    
    if(arr[mid]==k){
        return true;
    }
    
    // recursion call
    
    if(arr[mid]<k){
        return BinarySearch(arr,mid+1,e,k);
    }else{
         return BinarySearch(arr,s,mid-1,k);
    }
}

int main(){
    
    int arr[]={
        1,2,4,5,30
    };
    int ke = 2;
    
    if(BinarySearch(arr,0,4,ke)){
        cout<<"Element present in array.\n";
    }else{
         cout<<"Element not present in array.\n";
    }
    
    return 0;
}
