#include<bits/stdc++.h>

using namespace std;


vector<string> subsequences(string str){
	int n = str.length();
	int subStrings = (1<<n);
    vector<string>ans;
    
    
    
    for(int mask =1;mask<subStrings;mask++){
        string anss ="";
        for(int i=0;i<n;i++){
            if(((1<<i)&mask)){
                anss+=str[i];
            }            
        }
        ans.push_back(anss);
    }
    return ans;
    
	
}
int main(){
    
    vector<string> ans = subsequences("abc");
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}
