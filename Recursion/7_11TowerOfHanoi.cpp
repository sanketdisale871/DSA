//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function
    
   void solve(int src,int hep,int des,int n,long long &cnt){
        
        cnt++;
        // Base condition
        
        if(n==1){
       
            cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<des<<endl;
            return;
        }
        
        // fist n-1 disk moving from sender to helper
        solve(src,des,hep,n-1,cnt);
        
         cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<des<<endl;
         
         // moving n-1 disaks from helper to destination
         solve(hep,src,des,n-1,cnt);
         
         return ;
    }

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
       
       long long cnt = 0;
      solve(from,aux,to,N,cnt);
      return cnt;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends
