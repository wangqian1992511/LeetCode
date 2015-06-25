class MinStack {
public:
    MinStack() {
        sb.push(INT_MAX);    
    }
    
    void push(int x) {
        sa.push(x);
        if (x <= sb.top())
            sb.push(x);
    }

    void pop() {
        if (sa.top() == sb.top())
            sb.pop();
        sa.pop();
    }

    int top() {
        return sa.top();
    }

    int getMin() {
        return sb.top();
    }
private:
    stack<int> sa,sb;
};