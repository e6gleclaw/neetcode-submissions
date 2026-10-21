
class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Remove a node from its current position
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert a node immediately after head
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy nodes simplify insertion and deletion
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Mark this key as most recently used
        remove(node);
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {
        // Update existing key
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;

            remove(node);
            insertFront(node);
            return;
        }

        // No entries can be stored at zero capacity
        if (capacity == 0) return;

        // Evict least recently used node if full
        if (mp.size() == capacity) {
            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // Insert new key-value pair
        Node* node = new Node(key, value);
        insertFront(node);
        mp[key] = node;
    }
};
