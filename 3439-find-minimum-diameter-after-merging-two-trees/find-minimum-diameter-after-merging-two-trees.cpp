class Solution {
private:
    pair<int, int> doBFS(int node, vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(node);
        vector<int> vis(n, 0);
        vis[node] = 1;

        int levl = 0;
        int prvLvl = 0;
        int faNode = node;

        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                auto it = q.front();
                q.pop();
                for (auto itt : adj[it]) {
                    if (!vis[itt]) {
                        q.push(itt);
                        vis[itt] = 1;
                    }
                }

                if (levl > prvLvl) {
                    prvLvl = levl;
                    faNode = it;
                }
            }
            levl++;
        }
        return {levl - 1, faNode};
    }

    int findDist(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        auto p1 = doBFS(0, adj, n);
        auto p2 = doBFS(p1.second, adj, n); // Fixed missing semicolon

        return p2.first;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDist(edges1, edges1.size() + 1);
        int dia2 = findDist(edges2, edges2.size() + 1);

        int res = (dia1 + 1) / 2 + (dia2 + 1) / 2 + 1;

        if (dia1 > res && dia1 > dia2) {
            return dia1;
        }
        if (dia2 > res && dia2 > dia1) {
            return dia2;
        }

        return res;
    }
};
