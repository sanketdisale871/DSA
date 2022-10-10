#include<bits/stdc++.h>

using namespace std;


int main(){
    int arr[] = {2,5,1,4,9,12};
    int i = 3;
    
    /* THis below four syntax are correct */
    
    cout<<"arr[i] : "<<arr[i]<<endl;
    cout<<"*(arr+i) : "<<*(arr+i)<<endl;
    cout<<"i[arr] :"<<i[arr]<<endl;
    cout<<"*(i+arr) : "<<*(i+arr)<<endl;
   
    
    return 0;
}
