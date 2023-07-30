#include<iostream>

using namespace std;

struct Arry{
    int A[10];
    int size;
    int length;
};

void display(struct Arry arr){
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

int BS(struct Arry arr,int key){
    int l,h,m;
    l=0;
    h=arr.size;
    while(l<h){
        m=(l+h)/2;
        if(key==arr.A[m]){
            return m;
        }else if(key<arr.A[m]){
            h=m-1;
        }else{
            l=m+1;
        }

    }
    return -1;
}

int main(void){
    struct Arry arr1 = {{1,2,3,4,5,6},6,10};
    display(arr1);
    cout<<"The key is at index "<<BS(arr1,4);
    return 0;

}
