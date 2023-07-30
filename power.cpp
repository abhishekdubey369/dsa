#include<iostream>

using namespace std;
int pow(int a,int b){

    if(b>0){
        return a*pow(a,b-1);
    }else{
        return 1;
    }

}

int main(void){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<pow(a,b);
    return 0;

}