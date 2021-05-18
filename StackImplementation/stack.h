#ifndef _STACK_
#define _STACK_

class Stack {
    int top;
    int m_cap;
    int* arr;
    public:
    Stack(int size);             
    ~Stack();                   
    void push(int value);        
    int pop();                  
    int size();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int size){
    arr = new int[size];
    m_cap = size;
    top = -1;
}

Stack::~Stack(){
    delete[] arr;
}
void Stack::push(int value){
    if(isFull()){
        std::cout<<"Stack overflow";
        exit();
    }
    else{
        arr[++top] = value;
    }   
}
int Stack::pop(){
    if(isEmpty()){
        std::cout<<"Stack Underflow";
        exit();
    }
    else{

        return arr[top--];
    }
    int Stack::size(){
        return top + 1;
    }
    bool Stack::isFull(){
        return (top == m_cap - 1);
    }
    bool Stack::isEmpty(){
        return (top == -1);
    }




#endif
