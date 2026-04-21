class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(): key(0), val(0), prev(nullptr), next(nullptr) {}
        Node(int x, int y): key(x), val(y), prev(nullptr), next(nullptr) {}
    };

public:
    Node* head;
    Node* tail;
    int CAPACITY;
    int count;
    unordered_map<int, Node*> mp;

    void removeNode(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        if(p) p->next = node->next;
        else head = n;

        if(n) n->prev = p;
        else tail = p;
    }

    void addToFront(Node* node){
        node->prev = nullptr;
        node->next = head;

        if(head) head->prev = node;
        head = node;

        if(!tail) tail = node;
    }

    void moveToFront(Node* node){
        if(node == head) return;
        removeNode(node);
        addToFront(node);
    }

    LRUCache(int capacity) {
        CAPACITY = capacity;
        count = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        Node* node = it->second;
        moveToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it == mp.end()){
            if(count == CAPACITY){ //need to shift-left tail
                Node* lru = tail;
                mp.erase(lru->key);
                removeNode(lru);
                count--;
                delete lru;
            }

            Node* node = new Node(key, value);
            addToFront(node);
            mp[key] = node;
            count++;
            return;
        }

        Node* node = it->second;
        node->val = value;
        moveToFront(node);
        mp[key] = node;
    }
};
