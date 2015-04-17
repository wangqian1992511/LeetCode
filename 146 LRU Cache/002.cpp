struct DeListNode {
    int val, key;
    DeListNode *next, *prev;
    DeListNode(int x, int y) : val(x), key(y), next(NULL), prev(NULL) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        sum = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        else {
            update(cache[key]);
            return cache[key]->val;
        }
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end()) {
            DeListNode *p = new DeListNode(value, key);
            if (!sum) {
                sum++;
                head = tail = p;
            }
            else if (sum < capacity) {
                sum++;
                insertTail(p);
            }
            else {
                insertTail(p);
                DeListNode *q = head;
                head = head->next;
                head->prev = NULL;
                cache.erase(cache.find(q->key));
                delete q;
            }
            cache[key] = p;
        }
        else {
            cache[key]->val = value;
            update(cache[key]);
        }
    }
private:
    int capacity, sum;
    DeListNode *head, *tail;
    unordered_map<int, DeListNode*> cache;
    void insertTail(DeListNode *&p) {
        tail->next = p;
        p->prev = tail;
        tail = p;
        p->next = NULL; 
    }
    void update(DeListNode *&p) {
        if (!p->next) {
        }
        else if (!p->prev) {
            head = head->next;
            head->prev = NULL;
            insertTail(p);
        }
        else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            insertTail(p);
        }
    }
};