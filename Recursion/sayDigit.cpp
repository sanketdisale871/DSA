#include<bits/stdc++.h>

using namespace std;

void numberToWord(int n,string arr[]){
    
    if(n==0){
        return ;
    }
    
    int digit = n%10;
    n = n/10;
    numberToWord(n,arr);
    
    cout<<arr[digit]<<" ";
}

int main(){
    
    int n;cin>>n;
    
    string arr[]={
        "zero","one","two","three","four","five","six","seven","eigth","nine"
    };
    
    numberToWord(n,arr);
    
    cout<<endl;
    return 0;
}
