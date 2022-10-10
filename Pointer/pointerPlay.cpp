#include<bits/stdc++.h>

using namespace std;


int main(){
   int a = 10;
   int* p1 = &a;
   int** p2 = &p1;
   
   cout<<"\nPrinting Address of a :\n";
   cout<<&a<<endl;
   cout<<p1<<endl;
   cout<<*p2<<endl;
   
   cout<<"\nPrinting Value of a : \n";
   cout<<a<<endl;
   cout<<*p1<<endl;
   cout<<**p2<<endl;
   
   cout<<"\nPrinting Address of p1 :\n";
   cout<<&p1<<endl;
   cout<<p2<<endl;
   
    
    return 0;
}
