// DLL defintion and init
class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    // head and tail dummy nodes
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    // hashmap for lookup
    unordered_map<int, Node*> mp;
    int limit;
    // helper functions - addNode and delNode
    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

public:
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()){
            Node* getNode = mp[key];
            delNode(getNode);
            addNode(getNode);

            return getNode->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            Node* oldNode = mp[key];
            mp.erase(key);
            delNode(oldNode);
            delete oldNode;
        }
        if (mp.size() == limit){
            Node* oldNode = tail->prev;
            mp.erase(oldNode->key);
            delNode(oldNode);
            delete oldNode;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
