class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& t) 
    {
        unordered_map<char,int> m;
        for(auto e:garbage)
        {
            for(auto f:e)
            {
                m[f]++;
            }
        }
        
        int timem=0,timeg=0,timep=0;
        int n=garbage.size();
        vector<int> pre(t.size(),0);
        
        pre[0]=t[0];
        for(int i=1;i<t.size();i++)
        {
            pre[i]=pre[i-1]+t[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=garbage[i].size()-1;j>=0;j--)
            {
                if(garbage[i][j]=='P' && timep==0)
                {
                    if(i-1<0)
                    {
                        timep=m[garbage[i][j]];
                    }
                    else
                    {
                        timep=pre[i-1]+m[garbage[i][j]];
                    }
                    
                }
                else if(garbage[i][j]=='G' && timeg==0)
                {
                    if(i-1<0)
                    {
                        timeg=m[garbage[i][j]];
                    }
                    else
                    {
                        timeg=pre[i-1]+m[garbage[i][j]];
                    }
                }
                else if(garbage[i][j]=='M' && timem==0)
                {
                    if(i-1<0)
                    {
                        timem=m[garbage[i][j]];
                    }
                    else
                    {
                        timem=pre[i-1]+m[garbage[i][j]];
                    }
                }
            }
        }
        return timep+timem+timeg;
    }
};