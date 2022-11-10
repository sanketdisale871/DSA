#include<bits/stdc++.h>

using namespace std;

vector<string>ans;

void solve(string &s,int index,string &temp){
    
    // base case
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    
    // first descionn is capital
    
    char capch = s[index] & '_' ;
    temp+=capch;
    solve(s,index+1,temp);
    temp.pop_back();
    
    
    // second descionn is lower choic
    char lowch = s[index] | ' ';
    temp+=lowch;
    solve(s,index+1,temp);
    temp.pop_back();
    
}

int main(){
    
    string s = "ABC";
    string temp ="";
    solve(s,0,temp);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}
