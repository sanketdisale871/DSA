//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int>um;
        int n = s.length();
        int i = 0,j=0;
        int max_len = -1;
        
        while(j<n){
            // Calculation part
            um[s[j]]++;
            
            int condi = um.size();
            
            if(condi<k){ //
                j++;
            }
            else if(condi==k){
                max_len = max(max_len,j-i+1); // ansewer calculating
                j++;
            }
            else if(condi>k){
                
                while(um.size()>k){
                    if(um[s[i]]==1){ // removing out ou boundries
                        um.erase(s[i]);
                    }
                    else{
                        um[s[i]]--;
                    }
                    i++;
                }
                j++;
            }
            
        }
        return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
