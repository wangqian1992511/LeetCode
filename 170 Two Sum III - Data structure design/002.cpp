class TwoSum {
public:
	void add(int number) {
	    for (auto it = ele.begin(); it != ele.end(); it++) 
	        sum.emplace(*it + number);
	    ele.emplace(number);
	}
	bool find(int value) {
	    return sum.find(value) != sum.end();
	}
private:
    unordered_set<int> ele, sum;
};