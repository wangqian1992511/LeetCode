class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        while (!qa.empty()) {
            qb.push(qa.front());
            qa.pop();
        }
        qa.push(x);
        while (!qb.empty()) {
            qa.push(qb.front());
            qb.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        qa.pop();
    }

    // Get the top element.
    int top() {
        return qa.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return qa.empty();
    }
private:
    queue<int> qa, qb;
};