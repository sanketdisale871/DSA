//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string>ans;
    
    bool isSafe(int x,int y,vector<vector<int>> &m, vector<vector<int>>&visit){
        int n = m.size();
        
        if((x>=0 && y>=0) && (x<n && y<n) && (m[x][y]==1) && (visit[x][y]==0)){
            return true;
        } else{
            return false;
        }
        
        
    }
    
  void solve(int row,int col,vector<vector<int>> &m, vector<vector<int>>&visit,string &temp){
        int n = m.size();
        // Base Case
        if(row==(n-1) && col==(n-1)){
            ans.push_back(temp);
            return ;
        }
        
        // i entered into (0,0) 
        
        visit[row][col]=1;
        
        // down 
       int x = row+1;
        int y = col;
        if(isSafe(x,y,m,visit)){
            // mai down mai aa gaya
            temp.push_back('D');
            
            // recurrsive call
            solve(x,y,m,visit,temp);
            
            temp.pop_back();
        }
        
        // left
        x = row;
        y = col-1;
         if(isSafe(x,y,m,visit)){
            // mai down mai aa gaya
            temp.push_back('L');

            
            // recurrsive call
            solve(x,y,m,visit,temp);
            
            temp.pop_back();
        }       
        
        // right
        x = row;
        y = col+1;
         if(isSafe(x,y,m,visit)){
            // mai down mai aa gaya
            temp.push_back('R');

            
            // recurrsive call
            solve(x,y,m,visit,temp);
            
            temp.pop_back();
        }         
        
        // Up
        x = row-1;
        y = col;
         if(isSafe(x,y,m,visit)){
            // mai down mai aa gaya
            temp.push_back('U');

            
            // recurrsive call
            solve(x,y,m,visit,temp);
            
            temp.pop_back();
        }          
        
        
        
        // Bakctraking
        visit[row][col]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<int>>visit(n,vector<int>(n,0));
        
        string temp="";
        int row=0;
        int col =0;
        
       if(m[row][col]==1){
           solve(row,col,m,visit,temp);
           return ans;
       }else{
           return ans;
       }
        
       
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
