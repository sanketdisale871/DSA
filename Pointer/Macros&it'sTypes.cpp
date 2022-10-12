#include<bits/stdc++.h>
#define name "Sanket"
#define area(l,b) (l*b)
/* MultiLine Macro */
#define ELE 1,\
            2,\
            3    
/*Function Macro */

#define min(a,b) (((a)>(b))? (b) : (a))

using namespace std;

int main(){
    
    cout<<"My name is : "<<name<<endl;
    
    cout<<area(12,31)<<endl;
    
    int arr[]={ELE} ;
    
    cout<<"\nElements of Array : \n";
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int a =546;
    int b = 550;
    
    cout<<min(a,b)<<endl;
    
    
    
    
    return 0;
}
