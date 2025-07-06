class MinStack {
public:
    stack<int> S;
    stack<int> min_S;
    MinStack() {}

    void push(int val) {
        S.push(val);

        if (min_S.empty() || val <= min_S.top())
            min_S.push(val);
    }

    void pop() {

        if (min_S.top() == S.top())
            min_S.pop();

        S.pop();
    }

    int top() { return S.top(); }

    int getMin() { return min_S.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */