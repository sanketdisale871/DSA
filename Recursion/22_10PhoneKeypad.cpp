//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    vector<string>ans;
    
    void solve(int index,int a[],int n,string &temp,unordered_map<int,string> &um){
        
        // Base condition
        if(index==n){
            ans.push_back(temp);
            return;
        }
        
        int num = a[index];
        string value = um[num];
        
        for(int i=0;i<value.length();i++){
            char ch = value[i];
            
            // pushing the character in string
            temp.push_back(ch);
            
            // we are calling every character
            solve(index+1,a,n,temp,um);
            
            // Backtreaking
            temp.pop_back();
        }
        
        
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
       int index = 0 ;
       string temp ="";
       
       unordered_map<int,string> um = {
           {0,""},{1,""},{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{
               8,"tuv"},{9,"wxyz"}
           };
           
                  
       solve(index,a,N,temp,um);
       
       return ans;
           
       }

       
    
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends
