class Node {
public:
    int key, value, freq;
    list<Node*>::iterator it;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
    }
};

class LFUCache {
public:
    int capacity;
    int minFreq;

    unordered_map<int, Node*> mp;
    unordered_map<int, list<Node*>> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;

        freqList[freq].erase(node->it);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        node->freq++;

        freqList[node->freq].push_back(node);
        node->it = --freqList[node->freq].end();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (mp.size() == capacity) {
            auto &list = freqList[minFreq];

            Node* nodeToRemove = list.front();
            list.pop_front();

            mp.erase(nodeToRemove->key);
            delete nodeToRemove;

            if (list.empty()) {
                freqList.erase(minFreq);
            }
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;

        freqList[1].push_back(newNode);
        newNode->it = --freqList[1].end();

        minFreq = 1;
    }
};