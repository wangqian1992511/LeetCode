class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (keyToVal.count(key)) {
            lruCache.erase(keyToIterator[key]);
            lruCache.push_front(key);
            keyToIterator[key] = lruCache.begin();
            return keyToVal[key];
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        if (keyToVal.count(key)) {
            lruCache.erase(keyToIterator[key]);
        } else {
            capacity--;
            if (capacity < 0) {
                int delKey = lruCache.back();
                lruCache.pop_back();
                keyToIterator.erase(delKey);
                keyToVal.erase(delKey);
                capacity++;
            }
        }

        lruCache.push_front(key);
        keyToIterator[key] = lruCache.begin();
        keyToVal[key] = value;
    }
private:
    int capacity;
    unordered_map<int, int> keyToVal;
    unordered_map<int, list<int>::iterator> keyToIterator;
    list<int> lruCache;
};
