#include <unordered_map>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype> // for isalnum
#include <utility> // for pair

using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* next;
        node* prev;

        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = prev = nullptr;  // Optional but clean
        }
    };

    node* head;
    node* tail;
    int cap;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Add new node right after head
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Delete a node from DLL
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            node* resnode = mpp[key];
            int res = resnode->val;

            // Move node to front (MRU)
            deletenode(resnode);
            addnode(resnode);
            mpp[key] = head->next;

            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* existing = mpp[key];
            deletenode(existing);
            mpp.erase(key);
        }

        if (mpp.size() == cap) {
            // Remove LRU from DLL and map
            node* lru = tail->prev;
            mpp.erase(lru->key);
            deletenode(lru);
        }

        node* newnode = new node(key, value);
        addnode(newnode);
        mpp[key] = head->next;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache lru(capacity);

    while (true) {
        cout << "Enter command (get <key> / put <key> <value> / exit): ";
        string command;
        cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "get") {
            int key;
            cin >> key;
            int value = lru.get(key);
            cout << "Value: " << value << endl;
        } else if (command == "put") {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")" << endl;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;