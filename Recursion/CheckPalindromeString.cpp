#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(string &str,int i,int j){
    if(i>j){
        return true;
    }
    
    if(str[i]!=str[j]){
        return false;
    }else{
        i++;
        j--;
        return checkPalindrome(str,i,j);
    }
}

int main(){
    
    string str;cin>>str;
    
    if(checkPalindrome(str,0,str.length()-1)){
        cout<<"Given string is palindrome.";
    }else{
        cout<<"Given string is not palindrome.";

    }
    
    return 0;
}
