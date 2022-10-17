#include<bits/stdc++.h>

using namespace std;

void merge(int *arr,int s,int e){
    int mid = s + (e-s)/2 ;
    
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    int *first = new int[len1];
    int *second = new int[len2];
    
    int mainIndex = s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainIndex++];
    }
    
     mainIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainIndex++];
    }
    
    // merge two sorted arrys
    
   int minIndex = s;
    int index1 =0;
    int index2 = 0;
    
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[minIndex++]=first[index1++];
        }
        else{
             arr[minIndex++]=second[index2++];
        }
    }
    
    while(index1<len1){
         arr[minIndex++]=first[index1++];
    }
     while(index2<len2){
         arr[minIndex++]=second[index2++];
    }
}

void MergeSort(int *arr,int s,int e){
    
    if(s>=e){
        return;
    }
    
    int mid = s + (e-s)/2;
    
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    
    merge(arr,s,e);
    
}

int main(){
    int arr[8]={
        1,5,88,7,2,3,5,78
    };
    
    MergeSort(arr,0,7);
    
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
