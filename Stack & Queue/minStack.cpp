/*
Min Stack
Programming
Stacks And Queues
Medium
33.6% Success

336

98

Bookmark
Asked In:
Problem Description
 
 

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.


Q: What should pop do on empty stack? 
A: In this case, nothing. 



Q: What should top() do on empty stack?
A: In this case, return -1

NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor
*/

stack<int> st1;
stack<int> st2;

MinStack::MinStack() {
   while(!st1.empty())
    st1.pop();
   while(!st2.empty())
    st2.pop();
}

void MinStack::push(int x) {
    //cout<<"Push"<<endl;
    st1.push(x);
    if(st2.empty())
        st2.push(x);
    else{
        if(x<=st2.top())
            st2.push(x);
    }
    
    //cout<<"Push Ends"<<endl;
}

void MinStack::pop() {
    //cout<<"Pop"<<endl;
    int x;
    if(!st1.empty()){
        x = st1.top();
        st1.pop();
    }
        
    if(!st2.empty() && st2.top()==x)
        st2.pop();
    //cout<<"Pop Ends"<<endl;
}

int MinStack::top() {
   // cout<<"Top"<<endl;
    if(!st1.empty())
        return st1.top();
    else
        return -1;
    //cout<<"Top Ends"<<endl;
}

int MinStack::getMin() {
    //cout<<"Min"<<endl;
    if(!st2.empty())
        return st2.top();
    else
        return -1;
    //cout<<"Min Ends"<<endl;
}
