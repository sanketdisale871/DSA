
#include<bits/stdc++.h>

using namespace std;

bool linearSearch(int arr[],int key,int size){
   
    if(size==0){ // pura array check hua  --> Base condition
        return false;
    }
    
     if(arr[0]==key){ // check element present hai ya nahi   // Base Condition
        return true;  
    }
    else{
        return linearSearch(arr+1,key,size-1); // remaining array mai check kardo  // Processing + recursion call
    }
   
    
     
}

int main(){
    
    int arr[]={
        1,2,30,4,5
    };
    int ke = 30;
    
    if(linearSearch(arr,ke,5)){
        cout<<"Element present in array.\n";
    }else{
         cout<<"Element not present in array.\n";
    }
    
    return 0;
}
