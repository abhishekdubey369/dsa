#include<iostream>

using namespace std;
int b[10000];
int fib(int a){
    
    if(a<=1){
        b[a]=a;
        return a;
    }else{
        if(b[a-2]==-1){
            b[a-2]=fib(a-2);
        }if(b[a-1]==-1){
            b[a-1]=fib(a-1);
        }
        return b[a-1]+b[a-2];
    }

}
int main(void){
    for(int i=0;i<10000;i++){
    b[i] = -1;
}
    int a;
    cin>>a;
    cout<<fib(a);
    return 0;

}