class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node*next;
        node* prev;
        node(int k , int v){
            key = k;
            val = v;
            next =prev= NULL;
        }
    
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int , node*> m;
    int limit;
    LRUCache(int capacity) {
        limit =capacity;
        head->next = tail;
        tail->prev= head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        node* ansnode = m[key];
        int ans = ansnode->val;
        m.erase(key);
        delnode(ansnode);
        addnode(ansnode);
        m[key] = ansnode;

        return ans;
    }
   void addnode(node* newnode){
    node* oldnext = head->next;

    head->next = newnode;
    oldnext->prev = newnode;
    newnode->prev = head;
    newnode->next = oldnext;
   }
   void delnode(node* oldnode){
    node* oldprev = oldnode->prev;
    node* oldnext = oldnode->next;

    oldprev->next = oldnext;
    oldnext->prev = oldprev;
   }
    
    void put(int key, int value) {
       if(m.find(key) != m.end()){
        node* oldnode = m[key];
        delnode(oldnode);
        m.erase(key);
       }
       if(m.size() == limit){
        m.erase(tail->prev->key);
        delnode(tail->prev);
       }
       node* newnode = new node(key ,value);
        addnode(newnode);
        m[key] = newnode;
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */