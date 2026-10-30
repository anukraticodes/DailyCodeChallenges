class AllOne {
public:

    struct Bucket{
        int freq;
        unordered_set<string> st;
        Bucket* next;
        Bucket* prev;
        Bucket(int count) : freq(count), prev(nullptr), next(nullptr) {}
        Bucket* insertAfter(Bucket* node){
            node->prev=this;
            node->next=this->next;
            this->next->prev=node;
            this->next=node;
            return node;
        }

        void remove(){
            this->prev->next=this->next;
            this->next->prev=this->prev;
        }
    };
    Bucket* head;
    Bucket* tail;
    unordered_map<string, Bucket*> mp;
    AllOne() {
       head= new Bucket(0);
       tail = new Bucket(0);
       head->next= tail;
       tail->prev=head;
    }
    
    void inc(string key) {
        if(!mp.count(key)){
            if(head->next!=tail && head->next->freq == 1){
                auto b=head->next;
                b->st.insert(key);
                mp[key]=head->next;
            }
            else{
                Bucket* one=new Bucket(1);
                one->st.insert(key);
                head->insertAfter(one);
                mp[key]=head->next;
            }
        }
        else{
            Bucket* b = mp[key];
            int cnt=b->freq;
            b->st.erase(key);
            
            if(b->next == tail || b->next->freq != cnt+1){
                b->insertAfter(new Bucket(cnt+1));
            }
            b->next->st.insert(key);
            mp[key]=b->next;
            if(b->st.empty()) {
            b->remove();
            delete b;
        }
        }
    }
    
    void dec(string key) {
        auto b=mp[key];
        if(mp[key]->freq==1){
            b->st.erase(key);
            mp.erase(key);
        }
        else{
            b->st.erase(key);
            if(b->prev==head || b->prev->freq!=b->freq-1){
              b->prev->insertAfter(new Bucket(b->freq-1));
            }
            b->prev->st.insert(key);
            mp[key]=b->prev;
        }
          if(b->st.empty()) {
            b->remove();
            delete b;
          }
    }
    
    string getMaxKey() {
        if(head->next!=tail)return *(tail->prev->st.begin());
        return "";
    }
    
    string getMinKey() {
        if(head->next!=tail) return *(head->next->st.begin());
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */