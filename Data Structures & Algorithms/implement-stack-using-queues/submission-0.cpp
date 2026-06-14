class MyStack {
public:
        queue<int>q1;
        queue<int>q2;
    MyStack() {

        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int a = q1.front();
            q1.pop();
            q2.push(a);
        }
        swap(q2,q1);



        
    }
    
    int pop() {
        int a = q1.front();
        q1.pop();
        return a;
        
    }
    
    int top() {
        int b = q1.front();
        return b ;
        

    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */