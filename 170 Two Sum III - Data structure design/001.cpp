class TwoSum {
public:
	void add(int number) {
	    cnt[number]++;
	}
	bool find(int value) {
	    for (auto it = cnt.begin(); it != cnt.end(); it++) {
	        int x = it->first;
	        int y = value - x;
	        if ((x == y) && (cnt[x] > 1))
	            return true;
	        else if ((x != y) && (cnt.find(y) != cnt.end()))
	            return true;
	    }
	    return false;
	}
private:
    unordered_map<int, int> cnt;
};