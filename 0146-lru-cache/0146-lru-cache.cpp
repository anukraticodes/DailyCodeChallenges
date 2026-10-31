class LRUCache {
public:

    struct Node{
        int val;
        int k;
        Node* prev;
        Node* next;

        Node(int value, int ke){
            val=value;
            k=ke;
            prev=nullptr;
            next=nullptr;
        }
    };
    int counter=0;
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head= new Node(-1, -1);
        tail=new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        
        auto node=mp[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=tail;
        node->prev=tail->prev;
        tail->prev->next=node;
        tail->prev=node;
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(!mp.count(key)) {counter++;
        if(counter>cap){
            Node* newnode=new Node(value, key);
            tail->prev->next=newnode;
            newnode->prev=tail->prev;
            tail->prev=newnode;
            newnode->next=tail;
            mp[key]=newnode;
            mp.erase(head->next->k);
            head->next=head->next->next;
            head->next->prev=head;
            counter--;
        }
        else{
            Node* newnode=new Node(value, key);
            tail->prev->next=newnode;
            newnode->prev=tail->prev;
            tail->prev=newnode;
            newnode->next=tail;
            mp[key]=newnode;
        }
        }
        else{
            auto node=mp[key];
            node->val=value;

        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=tail;
        node->prev=tail->prev;
        tail->prev->next=node;
        tail->prev=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */