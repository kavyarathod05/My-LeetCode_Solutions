class Node {
public:
    Node* prev;
    Node* next;
    int key, val;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* front;
    Node* back;

    LRUCache(int capacity) {
        cap = capacity;
        front = new Node(0, 0);
        back = new Node(0, 0);
        front->next = back;
        back->prev = front;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key]; // Optional cleanup
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if (cache.size() > cap) {
            Node* lru = back->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

private:
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        Node* nextNode = front->next;
        front->next = node;
        node->prev = front;
        node->next = nextNode;
        nextNode->prev = node;
    }
};
