#include<bits/stdc++.h>

using namespace std;

int partition(int *arr,int s,int e){
    // Pivot element 
    int pivot = arr[s];
    
    //Place pivot element at right position
    int cnt =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){ // the element smaller than pivot
            cnt++;
        }
    }
    
    int pivotIndex = cnt+s; // finding right position for pivot element
    swap(arr[s],arr[pivotIndex]); 
    
    /* right and left part pivot element ka sambhal lo means left part mai less than pivot and right part mai greater than pivot */
    
    int i=s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        
        while(arr[i]<=pivot){
            i++;
        }
        
        while(arr[j]>pivot){
            j--;
        }
        
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
    
    
}

void QuickSort(int *arr,int s,int e){
    
    // base condition
    if(s>=e){
        return ;
    }
    
    int p= partition(arr,s,e); // it return the pivot element indext 
    
// left part ko sort kar de
    QuickSort(arr,s,p-1);
    
  // right part ko sort kar de
    QuickSort(arr,p+1,e);
}

int main(){
    
    int n;cin>>n;
    
    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    QuickSort(arr,0,n-1);
    cout<<"\nPrint element of array :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
}
