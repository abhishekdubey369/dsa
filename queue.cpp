#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        node(char x){data=x;}
};

class queue{
    private:
        node* que;
        node* front;
        node* rear;
    public:
        queue();
        void enqueue();
        void dequeue();
        void peek();
        void Rear();
        void isNull();
        void isFull();
        ~queue();
};

queue::queue(){
    que = nullptr;
    front = nullptr;
    rear = nullptr;
}




int main(void){
    return 0;
}