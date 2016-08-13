class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        n = 0;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = s.count(val);
        s.insert(val);
        n++;
        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!s.count(val))
            return false;
        s.erase(s.find(val));
        n--;
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return *next(s.begin(), rand() % n);
    }
private:
    unordered_multiset<int> s;
    int n;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
