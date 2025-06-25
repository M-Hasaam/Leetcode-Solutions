class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {}

    void push(int x) {
        if(s.empty()){
            s.push(x);
        }
        else{
            stack<int> s2;

            while(!s.empty()){
                s2.push(s.top());
                s.pop();
            }
            s.push(x);
            while(!s2.empty()){
                s.push(s2.top());
                s2.pop();
            }
        }
    }

    int pop() {
        int top=s.top();
        s.pop();
        return top;
    }

    int peek() {
       return s.top();
    }

    bool empty() {
      return s.empty();
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */