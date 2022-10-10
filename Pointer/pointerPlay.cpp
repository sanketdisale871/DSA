#include<bits/stdc++.h>

using namespace std;

void update(int **p2){
    
    // p2 = p2 + 1;
    // kucch chage hoga -> No
    
    // *p2 = *p2 + 1;
    // kucch chage hoga -> YES
    
     **p2 = **p2 + 1;
    // kucch chage hoga -> YES
    
    
}


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
   
   /*Double pointer as function */
   
   cout<<"\nBefore : "<<a<<endl;
   cout<<"\nBefore : "<<p1<<endl;
   cout<<"\nBefore : "<<p2<<endl;
   
   update(p2);
   
   cout<<"\nAfter : "<<a<<endl;
   cout<<"\nAfter : "<<p1<<endl;
   cout<<"\nAfter : "<<p2<<endl;

   
    
    return 0;
}
