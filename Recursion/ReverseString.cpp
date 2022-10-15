#include<bits/stdc++.h>

using namespace std;

void reverse (int i,int j,string &str){
    
    // base case 
    if(i>j){
        return ;
    }
    
    // one case solve karva do
    swap(str[i],str[j]);
    i++;
    j--;
    
    // baki ka recursion kar lega
    reverse(i,j,str);
}

int main(){
    
    string str;
   getline(cin,str);
    int i=0;
    int j = str.length()-1;
    
    reverse(i,j,str);
    
    cout<<str<<endl;
    
    
    
    return 0;
}
