#include<iostream>

using namespace std;

class sparse{

    private:
        int **S;
        int *row,*col,*data,t;
    public:
        sparse(int *r,int *c,int *d,int to);
        void display();
        void add(int **A,int **B);
        ~sparse();

};

sparse::sparse(int *r,int *c,int *d,int to){

    row=r;
    col=c;
    data=d;
    t=to;

    S = new int *[3];
    for(int i=0;i<3;i++){
        S[i] = new int [t];
    }

    for(int i=0;i<t;i++){
        S[0][i]=row[i];
    }

    for(int i=0;i<t;i++){
        S[1][i]=col[i];
    }

    for(int i=0;i<t;i++){
        S[2][i]=data[i];
    }

}

sparse::~sparse(){
    delete row;
    delete col;
    delete data;
    delete S;
}

void sparse::display(){
    for(int i=0;i<3;i++){
        for(int j=0;j<t;j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sparse::add(int **A,int **B){

}

int main(void){

    int A[] = {3,5,4,2,1};
    int B[] = {3,5,4,2,1};
    int C[] = {3,5,4,2,1};

    sparse M(A,B,C,5);
    M.display();

    return 0;
}