class LRUCache {
public:
    struct Node {
        Node *nxt, *prv;
        int key, val;
        Node(int k, int v) : key(k), val(v), nxt(nullptr), prv(nullptr) {}
    };

    int cap;
    Node *head, *tail; // Dummy sentinel nodes
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->nxt = tail;
        tail->prv = head;
    }

    void removeNode(Node* node) {
        node->prv->nxt = node->nxt;
        node->nxt->prv = node->prv;
    }

    void addNode(Node* node) { // Inserts right after dummy head
        node->nxt = head->nxt;
        node->prv = head;
        head->nxt->prv = node;
        head->nxt = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        
        Node* node = mp[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNode(node);
            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prv; // Real LRU node
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};