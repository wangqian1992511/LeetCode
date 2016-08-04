class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s.count(val))
            return false;
        s.insert(val);
        n++;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!s.count(val))
            return false;
        s.erase(val);
        n--;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return *next(s.begin(), rand() % n);
    }
private:
    unordered_set<int> s;
    int n;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
