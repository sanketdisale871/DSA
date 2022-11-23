#include <bits/stdc++.h> 

int partition(vector<int> &arr,int s,int e){
    // Pivot element 
    int pivot = arr[s];
    
    //Place pivot element at right position
    int cnt =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){ // the element smaller than pivot
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

void QuickSort(vector<int> &arr,int s,int e){
    
    // base condition
    if(s>=e){
        return ;
    }
    
    int p= partition(arr,s,e); // it return the pivot element indext 
    
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}



vector<int> quickSort(vector<int> arr)
{
    int e = arr.size()-1;
   QuickSort(arr,0,e);
     
    return arr;
}
