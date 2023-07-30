#include <iostream>

using namespace std;

struct Arry{
    int A[10];
    int size;
    int length;
};

void Display(struct Arry arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int LS(struct Arry *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            return i;
        }
    }
    return -1;
}

int main(void){
    struct Arry arr1 ={{1,2,3,4,50},5,10};
    cout<<"The searched element is fount at position"<<LS(&arr1, 50);
    return 0;
}