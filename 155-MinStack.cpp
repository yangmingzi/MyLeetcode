//两个栈组合实现
class MinStack {
private:
    stack<int> s;
    stack<int> sm;
public:
    void push(int x) {
        s.push(x);
        if(sm.empty() || x<=sm.top())//不是x<sm.top,是<=
            sm.push(x);
    }

    void pop() {
        if(s.top()==sm.top())
            sm.pop();
        s.pop();        
    }

    int top() {
        return s.top();

    }

    int getMin() {
        return sm.top();
    }
};