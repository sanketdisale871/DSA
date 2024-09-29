class AllOne {
public:
    set<pair<int,string>> incrs;
    set<pair<int,string>,greater<>> decrs;
    unordered_map<string, int> um;

    AllOne() {
    }

    void inc(std::string key) {
        if (um.find(key) != um.end()) {
            incrs.erase({um[key], key});
            decrs.erase({um[key], key});
        }
        um[key]++;

        incrs.insert({um[key], key});
        decrs.insert({um[key], key});
    }

    void dec(std::string key) {
        if (um.find(key) != um.end()) {
            incrs.erase({um[key], key});
            decrs.erase({um[key], key});
        }
        um[key]--;

        if (um[key] > 0) {
            incrs.insert({um[key], key});
            decrs.insert({um[key], key});
        } else {
            um.erase(key);  
        }
    }

    std::string getMaxKey() {
        if (decrs.empty()) {
            return "";
        }
        return decrs.begin()->second;
    }

    std::string getMinKey() {
        if (incrs.empty()) {
            return "";
        }
        return incrs.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * std::string param_3 = obj->getMaxKey();
 * std::string param_4 = obj->getMinKey();
 */
