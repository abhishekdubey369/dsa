#include <iostream>

using namespace std;

struct Array{
    int *p;
    int size;
    int length;
};


void merge(struct Array *a,struct Array *b){
    int size=a->size+b->size;
    int c[size];
    int i=0,j=0,k=0;
    while(i<a->size && j<b->size){
        if(a->p[i]<b->p[j]){
        c[k]=a->p[i];
        i++;
        k++;
    }else{
        c[k]=b->p[j];
        j++;
        k++;
    }
    }
    for(;i<a->size;i++){
        c[k]=a->p[i];
        k++;
    }
    for(;j<b->size;j++){
        c[k]=b->p[j];
        k++;
    }
    cout<<"here is merg ";
    for(int i=0;i<size;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}


int main(void){
    int ar[]={1,2,30,40,50,60};
    int ar2[]={4,15,26,55,90,108,112};
    struct Array a={ar,6,10};
    struct Array a1={ar2,7,10};
    merge(&a,&a1);
    return 0;
}