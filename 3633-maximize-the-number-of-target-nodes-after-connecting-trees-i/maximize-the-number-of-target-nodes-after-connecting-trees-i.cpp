class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& ed1, vector<vector<int>>& ed2, int k) {
        int m = ed1.size();
        int n = ed2.size();

        // Use vector of vectors for adjacency lists
       
       

        // Build adjacency lists
        for (auto it : ed1) {
            m = max(m,it[0]);
            m = max(m,it[1]);

        }
         vector<vector<int>> adj1(m+1);
        for (auto it : ed1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for (auto it : ed2) {
            n = max(n,it[0]);
            n = max(n,it[1]);
        }
         vector<vector<int>> adj2(n+1);
        for (auto it : ed2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        // Now, adjacency lists are ready
        int maxReach = 0;

        for (int i = 0; i < n+1; i++) {
            int cnt = 0;
            // pair<distance, node>
            queue<pair<int, int>> q;
            vector<int> vis(n+1, 0);
            q.push({1, i});
            vis[i] = 1;

            while (!q.empty()) {
                auto it = q.front();
                q.pop();

                int cst = it.first;
                int node = it.second;

                if (cst > k) {
                    break;
                }

                cnt++;

                for (auto neighbor : adj2[node]) {
                    if (!vis[neighbor]) {
                        q.push({cst + 1, neighbor});
                        vis[neighbor] = 1;
                    }
                }
            }
            maxReach = max(maxReach, cnt);
        }

        vector<int>ans;

        for(int i=0;i<m+1;i++){
               int cnt = 0;
            // pair<distance, node>
            queue<pair<int, int>> q;
            vector<int> vis(m+1, 0);
            q.push({0, i});
            vis[i] = 1;

            while (!q.empty()) {
                auto it = q.front();
                q.pop();

                int cst = it.first;
                int node = it.second;

                if (cst > k) {
                    break;
                }

                cnt++;

                for (auto neighbor : adj1[node]) {
                    if (!vis[neighbor]) {
                        q.push({cst + 1, neighbor});
                        vis[neighbor] = 1;
                    }
                }
            }
            ans.push_back(cnt+maxReach);
        }

        return ans;
    }
};
