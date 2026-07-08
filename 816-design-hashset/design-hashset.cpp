#include <unordered_set>

class MyHashSet {
    unordered_set<int> s;

public:
    void add(int key) {
        s.insert(key);
    }

    void remove(int key) {
        s.erase(key);
    }

    bool contains(int key) {
        return s.find(key) != s.end();
    }
};