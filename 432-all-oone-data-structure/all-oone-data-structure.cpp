#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>

// Custom hash function for std::pair<int, std::string>
// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator()(const std::pair<T1, T2>& p) const {
//         auto hash1 = std::hash<T1>{}(p.first);
//         auto hash2 = std::hash<T2>{}(p.second);
//         return hash1 ^ (hash2 << 1); // Combine the two hash values
//     }
// };

class AllOne {
public:
    // Use the custom hash function for unordered_set
    set<std::pair<int, std::string>> incrs;
  set<std::pair<int, std::string>, std::greater<>> decrs;
    std::unordered_map<std::string, int> um;

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
            um.erase(key);  // Remove the key from the map if the count becomes 0
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
