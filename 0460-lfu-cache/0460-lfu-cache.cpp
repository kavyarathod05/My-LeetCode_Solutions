class Node {
public:
    Node* prev;
    Node* next;
    int key, value, freq;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        Node* front = head->next;

        node->next = front;
        node->prev = head;

        head->next = node;
        front->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* removeLast() {
        if (head->next == tail) return nullptr;

        Node* node = tail->prev;
        remove(node);
        return node;
    }

    bool isEmpty() {
        return head->next == tail;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> nodeMap;
    unordered_map<int, DLL*> freqMap;

    int minFreq;
    int cap;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;

        freqMap[freq]->remove(node);

        if (freqMap[freq]->isEmpty()) {
            if (minFreq == freq) minFreq++;
        }

        node->freq++;

        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLL();
        }

        freqMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) return -1;

        Node* node = nodeMap[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (nodeMap.size() == cap) {
            DLL* list = freqMap[minFreq];

            Node* nodeToRemove = list->removeLast();

            nodeMap.erase(nodeToRemove->key);

            delete nodeToRemove;
        }

        Node* newNode = new Node(key, value);

        nodeMap[key] = newNode;

        if (freqMap.find(1) == freqMap.end()) {
            freqMap[1] = new DLL();
        }

        freqMap[1]->addFront(newNode);

        minFreq = 1;
    }
};