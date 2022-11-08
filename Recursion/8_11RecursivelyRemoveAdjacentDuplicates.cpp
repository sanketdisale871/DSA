//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:

    string modi(string str){
       
        string res ="";
       
      int i = 0;
       
      while(str[i]){
           
          // first condition 
          if(str[i]!=str[i+1]){
              res+=str[i];
              i++;
          }
           
          if(str[i] && (str[i]==str[i+1])){
               
              while(str[i] && (str[i]==str[i+1])){
                  i++;
              }
              i++;
          }
      }
       
      return res;
    
   
    
    }

    string rremove(string s){
       
       string pvs;
       
       while(pvs.size()!=s.size()){
           pvs = s;
           s=modi(s);
       }
       return pvs;
       
  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends
