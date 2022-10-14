#include<bits/stdc++.h>

using namespace std;

int sum(int arr[],int size){
  
  if(size==0){
      return 0;
  }
  
  int digit = arr[0];
  
 int su = sum(arr+1,size-1);
  
   
  return  su+=digit;
}

int main(){
    
    int n;cin>>n;
    int *arr;
    arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
   cout<<"Sum : "<<sum(arr,n)<<endl;
    
    return 0;
}
