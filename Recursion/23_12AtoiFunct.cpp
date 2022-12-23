//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int anss = 0;
    int mul = 1;
    
    int makeNum(int digit){
        // Base case
        digit = digit*mul;
        mul*=10;
        return digit;
    }
    
    void makeAtoi(string &str,int size,int i){
        // Base case
        if(size==0){
            return ;
        }
        
        int digit = str[i]-'0';
        makeAtoi(str,size-1,i+1);
        
        anss+=makeNum(digit);
    }
    
    int atoi(string str) {
       
       for(int i=0;i<str.size();i++){
           if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || i!=0 && str[i]>='*' && str[i]<='/' ){
               return -1;
           }
       }
       
       if(str[0]=='-'){
           makeAtoi(str,str.size()-1,1);
           return -anss;
       }
       else{
           makeAtoi(str,str.size(),0);
           return anss;
       }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
