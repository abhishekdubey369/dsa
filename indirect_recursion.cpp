#include<iostream>

using namespace std;
int funB(int);
int funA(int a){

    if(a>0){
        return a + funB(a-1);
    }else{
        return 0;
    }

}
int funB(int b){
    if(b>0){
        return b + funA(b-1);
    }else{
        return 0;
    }
}

int main(void){
    int a;
    cin>>a;
    cout<<funA(a);
    return 0;

}