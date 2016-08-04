class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        used = new bool [maxNumbers];
        for (int i = 0; i < maxNumbers; i++) {
            q.push(i);
            used[i] = false;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (q.empty())
            return -1;
        int x = q.front();
        used[x] = true;
        q.pop();
        return x;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (used[number]) {
            used[number] = false;
            q.push(number);
        }
    }
private:
    queue<int> q;
    bool* used;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
