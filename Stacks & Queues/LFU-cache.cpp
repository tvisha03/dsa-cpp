#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;


class LFUCache {
private:
    int cap;
    int minFreq;
    unordered_map<int,int> keyToVal;
    unordered_map<int,int> keyToFreq;
    unordered_map<int,list<int>> freqToKeys;
    unordered_map<int,list<int>::iterator> keyIter;
public:
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
        
    }
    
    int get(int key) {
        if(keyToVal.find(key)==keyToVal.end()) return -1;
        int freq =keyToFreq[key];
        freqToKeys[freq].erase(keyIter[key]);
        keyToFreq[key]++;
        freqToKeys[freq+1].push_front(key);
        keyIter[key]=freqToKeys[freq+1].begin();

        if(freqToKeys[freq].empty()){
            freqToKeys.erase(freq);
            if(minFreq==freq) minFreq++;
        }
        return keyToVal[key];
        
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(keyToVal.find(key)!=keyToVal.end()){
            keyToVal[key]=value;
            get(key);
            return;
        }
        if(keyToVal.size()==cap){
            int evictKey=freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            keyToVal.erase(evictKey);
            keyToFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }
        keyToVal[key]=value;
        keyToFreq[key]=1;
        minFreq=1;
        freqToKeys[1].push_front(key);
        keyIter[key]=freqToKeys[1].begin();
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LFUCache lfu(2);
    lfu.put(1, 1); // cache is {1=1}
    lfu.put(2, 2); // cache is {1=1, 2=2}
    cout << lfu.get(1) << endl; // returns 1
    lfu.put(3, 3); // evicts key 2, cache is {1=1, 3=3}
    cout << lfu.get(2) << endl; // returns -1 (not found)
    lfu.put(4, 4); // evicts key 1, cache is {3=3, 4=4}
    cout << lfu.get(1) << endl; // returns -1 (not found)
    cout << lfu.get(3) << endl; // returns 3
    cout << lfu.get(4) << endl; // returns 4
    return 0;