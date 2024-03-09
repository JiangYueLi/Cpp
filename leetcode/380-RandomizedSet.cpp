#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val) == 0)
        {   
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.count(val))
        {
            int back = v[v.size()-1];
            m[back] = m[val];
            swap(back,v[m[val]]);
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = (rand()%(v.size()));
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */