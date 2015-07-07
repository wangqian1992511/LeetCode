class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!sb.empty()) {
            sa.push(sb.top());
            sb.pop();
        }
        sb.push(x);
        while (!sa.empty()) {
            sb.push(sa.top());
            sa.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        sb.pop();
    }

    // Get the front element.
    int peek(void) {
        return sb.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sb.empty();
    }
private:
    stack<int> sa, sb;
};