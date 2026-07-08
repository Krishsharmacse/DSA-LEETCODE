#include <unordered_set>
class MyHashSet {
public:
  
        unordered_set<int>map;
        
    
    
    void add(int key) {
        map.insert(key);
        
    }
    
    void remove(int key) {
        map.erase(key);
        
    }
    
    bool contains(int key) {
        return map.find(key)!=map.end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */