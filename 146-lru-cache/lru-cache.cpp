
class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map <int, Node*> mp;
    int cap = 0;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        cout << "capaciity set to " << cap << endl;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            Node* pos = mp[key];
            // remove it from where it is 
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;

            // now add it in front of head
            pos->prev = head;
            pos->next = head->next;

            pos->prev->next = pos;
            pos->next->prev = pos;

            mp[key] = pos;
            return pos->val;
        }
    }
    
    void put(int key, int value) {
        // here there can be 2 cases if the element is already present or not
        // if already present no matter the capacity we will update and take it to front 
        // else check cap if overflows then remove the elemnt just before tail and add the new at the begining
        // or if doesnot over flows then just add at start 
        if(mp.find(key) != mp.end()){
            Node* pos = mp[key];
            // remove it from where it is 
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;

            pos->val = value;

            // now add it in front of head
            pos->prev = head;
            pos->next = head->next;

            pos->prev->next = pos;
            pos->next->prev = pos;

            mp[key] = pos;
        }
        else{
            // if capacity = 0 then we have to first remove the last guy
            cout << "capacity before adding " << key << " " << value << " is " << cap <<endl;
            if(cap <= 0){
                Node* pos = tail->prev;
                pos->prev->next = pos->next;
                pos->next->prev = pos->prev;

                pos->next = NULL;
                pos->prev = NULL;

                mp.erase(pos->key);
                delete(pos);
                cap++;
            }
            Node* temp = new Node(key, value);
            temp->prev = head;
            temp->next = head->next;
            
            head->next->prev = temp;
            head->next = temp;
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