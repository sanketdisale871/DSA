
// recurrsion and backtracking approch (runtime comp : 22ms)
class Solution {
public:
    
    vector<string>ans;
    
    void solve(int index,string s,vector<string>&temp){
        
        int m = temp.size(),n=s.size();
        
        // Base case : if number of ip address in the vector is 4 & all string is traversed
        if(index==n && m==4){
            ans.push_back(temp[0]+'.'+temp[1]+'.'+temp[2]+'.'+temp[3]);
            return;
        }
        
        // if either out of the index or number of ip address greater than 4 then just return
        if(index>n && m>4){
            return;
        }
        
        // looping for diff length of ip addre from current index
        
        for(int i=0;i<3;i++){
            
            // if it is possible to have ip address (i+1) length
            
            if(index+i<=n){
                
                string str = s.substr(index,i+1);
                
                // if curretn ip is valid
                
                if((i==0 and str>="0" and str<="9") or (i==1 and str>="10" and str<="99") or (i==2 and str>="100" and str<="255")){
                    
                    temp.push_back(str);
                    
                    solve(index+i+1,s,temp);
                    
                    // backtrakkng
                    temp.pop_back();
                }
            }
        }
        return;
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        int index = 0;
        vector<string>temp;
        
        solve(index,s,temp);
        
        return ans;
    }
};


// recurssion and dfs approach (runtime comp : 7ms)

class Solution {
    vector<string> ans;
public:
    void restoreDFS(string s, string temp, int dot, int index) {
        if (index == s.size() and dot == 4) {
            temp.pop_back();
            ans.push_back(move(temp));
            return;
        }
        if (index >= s.size() or dot >= 4) {
            return;
        }
		
        // case 1: For first dot it doesnot matter what number it is
        restoreDFS(s, temp + s[index] + '.', dot + 1, index + 1);
		
		// case 2: For 2 numbers the first char cannot be a zero
        if (s[index] != '0') {
            restoreDFS(s, temp + s.substr(index, 2) + '.', dot + 1, index + 2);
        }
		
		// case 3: For 3 numbers whole number cannot be larger than 255 with no leading zero
        if (s[index] != '0' and (stoi(s.substr(index, 3)) < 256)) {
            restoreDFS(s, temp + s.substr(index, 3) + '.', dot + 1, index + 3);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 or s.size() < 4) return ans;
        restoreDFS(s, "", 0, 0);
        return ans;
    }
};
