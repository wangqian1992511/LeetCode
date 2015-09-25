class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        p1 = p2 = 0;
        isOne = !v1.empty();
    }

    int next() {
        int x;
        if (isOne) {
            x = v1[p1++];
            if (p2 < v2.size())
                isOne ^= true;
        }
        else {
            x = v2[p2++];
            if (p1 < v1.size())
                isOne ^= 1;
        }
        return x;
    }

    bool hasNext() {
        return isOne && (p1 != v1.size()) || !isOne && (p2 != v2.size());
    }
private:
    vector<int> v1, v2;
    int p1, p2;
    bool isOne;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
