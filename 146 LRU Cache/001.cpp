class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        sum = t = 0;
        heap = new int [capacity];
        seq = new int [capacity];
    }
    
    int get(int key) {
        t++;
        if (cache.find(key) == cache.end())
            return -1;
        else {
            seq[pos[key]] = t;
            sink(pos[key]);
            return cache[key];
        }
    }
    
    void set(int key, int value) {
        t++;
        if (cache.find(key) == cache.end()) {
            cache[key] = value;
            if (sum < capacity) {
                heap[sum] = key;
                pos[key] = sum;
                seq[sum++] = t;
            }
            else {
                int rplc = heap[0];
                cache.erase(cache.find(rplc));
                pos.erase(pos.find(rplc));
                heap[0] = key;
                pos[key] = 0;
                seq[0] = t;
                sink(0);
            }
        }
        else {
            cache[key] = value;
            seq[pos[key]] = t;
            sink(pos[key]);
        }
    }
private:
    int capacity, t, sum;
    int *heap, *seq;
    map<int, int> cache, pos;
    void sink(int x) {
        int key = seq[x];
        int tmp = heap[x];
        while ((x << 1) + 1 < sum) {
            int l = (x << 1) + 1;
            int r = l + 1;
            int t = l;
            if ((r < sum) && (seq[r] < seq[l]))
                t = r;
            if (seq[t] < key) {
                seq[x] = seq[t];
                heap[x] = heap[t];
                pos[heap[t]] = x;
                x = t;
            }
            else
                break;
        }
        seq[x] = key;
        heap[x] = tmp;
        pos[tmp] = x;
    }
};