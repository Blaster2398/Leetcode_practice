class LRUCache {
    class Node{
    public:
        int key;
        int val;
        Node* nxt;
        Node* pre;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            nxt = NULL;
            pre = NULL;
        }
    };

    // we need a doubly linked list and a map<int, Node*>
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int cap=0;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head->nxt = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* pos = mp[key];

        // remove it from the pos and then add it the front 
        pos->pre->nxt = pos->nxt;
        pos->nxt->pre = pos->pre;
        head->nxt->pre = pos;
        pos->nxt = head->nxt;

        head->nxt = pos;
        pos->pre = head;

        mp[key] = pos;
        return pos->val;

    }
    
    void put(int key, int val) {
        // there are 2 cases 
        // we find it ( we have to make it to the front )
        // we didnt check the capacity ( remove somethig and then add it to the front )
        if(mp.find(key) != mp.end()){
            Node* pos = mp[key];
            pos->val = val;
            // remove the node from the curr pos 
            pos->pre->nxt = pos->nxt;
            pos->nxt->pre = pos->pre;

            // add it to the front
            head->nxt->pre = pos;
            pos->nxt = head->nxt;

            head->nxt = pos;
            pos->pre = head;

            mp[key] = pos;
        }
        // if cap <= 0 then remove the last till it is > 0
        else{
            if(cap <= 0){
                Node* pos = tail->pre;
                int key2 = pos->key;
                pos->pre->nxt = pos->nxt;
                pos->nxt->pre = pos->pre;

                pos->nxt = NULL;
                pos->pre = NULL;

                mp.erase(key2);
                delete(pos);
                cap++;
            }
            Node* temp = new Node(key, val);
            head->nxt->pre = temp;
            temp->nxt = head->nxt;

            head->nxt = temp;
            temp->pre = head;
            mp[key] = temp;
            cap--;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */