class MinStack {
    stack<int> stk;
    vector<int> prefix_min;
public:
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if (prefix_min.size() == 0) {
            prefix_min.push_back(val);
        }
        else {
            prefix_min.push_back(val);
            int last_idx = (int)prefix_min.size() - 1;
            prefix_min[last_idx] = min(prefix_min[last_idx], prefix_min[last_idx - 1]);
        }
    }
    
    void pop() {
        stk.pop();
        prefix_min.pop_back();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        int last_idx = (int)prefix_min.size() - 1;
        return prefix_min[last_idx];
    }
};