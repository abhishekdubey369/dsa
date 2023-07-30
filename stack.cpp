#include<iostream>

using namespace std;

//method1

typedef struct stack{
    int size;
    int top;
    int *S;
} stack;

void push(stack *s,int x){
    if(s->top==s->size-1){
        cout<<"overflow";
    }else{
        s->top++;
        s->S[s->top]=x;
    }
}

void pop(stack *s){
    if(s->top==-1){
        cout<<"underflow";
    }else{
        cout<<s->S[s->top]<<endl;
        s->top--;
    }
}


//method 2

class Stack{
    
    private:
        int size;
        int top;
        int *S;
    public:
        Stack(int s);
        void push(int x);
        int pop();
        int isEmpty();
        int isFull();
        void peek(int index);
        void display();
        ~Stack(){
            delete []S;
        }

};

Stack::Stack(int s){

    size=s;
    S=new int[size];
    top=-1;
    
}

void Stack::push(int x){

    if(top==size-1){
        cout<<"overflow"<<endl;
    }else{
        top++;
        S[top]=x;
    }

}

int Stack::pop(){

    int m;
    if(top==-1){
        cout<<"underflow"<<endl;
        return -1;
    }else{
        m=S[top];
        top--;
    }
    return m;

}

int Stack::isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

int Stack::isFull(){
    if(top==size-1){
        return 1;
    }else{
        return 0;
    }
}

void Stack::peek(int index){

    if(top-index+1<0){
        cout<<"Invalid"<<endl;
    }else{
        cout<<S[top-index+1]<<endl;
    }

}

void Stack::display(){

    int m=top;
    while(m!=-1){
        cout<<S[m--]<<" ";
    }cout<<endl;

}

int main(void){
    Stack s1(5);
    cout<<s1.isEmpty()<<endl;
    cout<<s1.isFull()<<endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(50);
    s1.display();
    s1.peek(3);
    cout<<s1.isEmpty()<<endl;
    cout<<s1.isFull()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    return 0;
}