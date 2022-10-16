/*
    *Required things for recutsion :
    - base condition necessary
    - processing optional
    -recurance relation
*/
#include<bits/stdc++.h>

using namespace std;

long power(int a,int b){
    
    if(b==0){
        return 1;
    }
    
    long result = power(a,b/2);
    
    if(b&1){
        return (a * result * result);
    }else{
        return (result*result);
    }
    
   
}

int main(){
    
   int a,b;
   cin>>a>>b;
    
   cout<< power(a,b);
    
    
    return 0;
}
