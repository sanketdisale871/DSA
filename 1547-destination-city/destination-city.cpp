class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sourceCities;
        for (const auto& path : paths) {
            sourceCities.insert(path[0]);
        }
        for (const auto& path : paths) {
            if (sourceCities.find(path[1]) == sourceCities.end()) {
                return path[1];
            }
        }
        return "";
    }
};