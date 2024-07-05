class Node{
    public:
        int key;
        int val;
        int cnt;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            cnt = 1;
            next = NULL;
            prev = NULL;
        }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        this->maxSizeCache = capacity;
        this->minFreq = 0;
        this->currSize = 0;
    }

    void updateFreqListMap(Node* node){
        // first erase the node from both the maps 
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        // check if the freq from where you deleted the node was the min freq if it was then cheeck if it became empty
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            minFreq++;
        }

        // make new higher freq list if it is alredy present just update it 
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt+1];
        }
        node->cnt++;
        nextHigherFreqList->addFront(node);

        // again add this node back to the 2 maps 
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    

    int get(int key) {
        if(keyNode.find(key) == keyNode.end()){
            return -1;
        }
        else{
            Node* node = keyNode[key];
            updateFreqListMap(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else{
            // check if the size has reached its peak delete a element from min freq list 
            if(currSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            // new node to be added 
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }

            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//  int get(int key) {
//         if(mp.find(key) == mp.end()){
//             return -1;
//         }
//         else{
//             Node* pos = mp[key];
//             // remove it from where it is 
//             pos->prev->next = pos->next;
//             pos->next->prev = pos->prev;

//             // now add it in front of head
//             pos->prev = head;
//             pos->next = head->next;

//             pos->prev->next = pos;
//             pos->next->prev = pos;

//             mp[key] = pos;
//             return pos->val;
//         }
//     }
    
//     void put(int key, int value) {
//         // here there can be 2 cases if the element is already present or not
//         // if already present no matter the capacity we will update and take it to front 
//         // else check cap if overflows then remove the elemnt just before tail and add the new at the begining
//         // or if doesnot over flows then just add at start 
//         if(mp.find(key) != mp.end()){
//             Node* pos = mp[key];
//             // remove it from where it is 
//             pos->prev->next = pos->next;
//             pos->next->prev = pos->prev;

//             pos->val = value;

//             // now add it in front of head
//             pos->prev = head;
//             pos->next = head->next;

//             pos->prev->next = pos;
//             pos->next->prev = pos;

//             mp[key] = pos;
//         }
//         else{
//             // if capacity = 0 then we have to first remove the last guy
//             cout << "capacity before adding " << key << " " << value << " is " << cap <<endl;
//             if(cap <= 0){
//                 Node* pos = tail->prev;
//                 pos->prev->next = pos->next;
//                 pos->next->prev = pos->prev;

//                 pos->next = NULL;
//                 pos->prev = NULL;

//                 mp.erase(pos->key);
//                 delete(pos);
//                 cap++;
//             }
//             Node* temp = new Node(key, value);
//             temp->prev = head;
//             temp->next = head->next;
            
//             head->next->prev = temp;
//             head->next = temp;
//             mp[key] = temp;
//             cap--;
//         }

//     }