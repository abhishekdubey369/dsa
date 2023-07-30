#include<iostream>

using namespace std;

class node{
    public:
        node *Rchild;
        int data;
        node *Lchild;
};

class bst{
    private:
        node *bt;
        int sum;
    public:
        bst(){bt = nullptr;}
        void inorder(node  *p);
        void inorder(){inorder(bt);};
        node* deletebt(int key){
            return deletebt(bt,key);
        }
        void deleteleaf(){
            deleteleaf(bt);
        }
        void greatsum(){
             greatsum(bt,bt->data);
        }
        int greatsum(node* p,int tl);
        node* construct(int *x);
        void deleteleaf(node *p);
        node* deletebt(node *p,int x);
        node* Rsearch(int key){
            return Rsearch(bt,key);
        }
        node* Rsearch(node *p,int key);
        void Insert(int key);
        ~bst(){delete bt;}
};
int bst::greatsum(node* p,int tl){
    sum = tl;
    node* temp=p;
    if(temp->Rchild==nullptr){
        return sum;
    }
    else{
        temp->data += greatsum(temp->Rchild,temp->data);
    }
    p->data=temp->data;
    greatsum(p->Lchild,p->Lchild->data);
    greatsum(p->Rchild,p->Rchild->data);
    return sum;
}

node* bst::deletebt(node *p,int x){
        if(p==nullptr){return p;}
        if(p->data>x){
            p->Lchild=deletebt(p->Lchild,x);
            return p;
        }else if(p->data<x){
            p->Rchild=deletebt(p->Rchild,x);
            return p;
        }
        if(p->Rchild==nullptr){
            node *t=p->Lchild;
            delete p;
            return t;
        }else if(p->Lchild==nullptr){
            node *t=p->Rchild;
            delete p;
            return t;
        }
        else{
            node *a =p;
            node *b=p->Rchild;
            while(b!=nullptr){
                a = b;
                b=b->Lchild;
            }
            if(a!=p){
                a->Lchild=b->Rchild;
            }else{
                a->Rchild=b->Rchild;
            }
            p->data=b->data;
            return p;
        }
}

void bst::deleteleaf(node *p){
    while(p!=nullptr){
        if(p->Lchild==nullptr && p->Rchild==nullptr){
            p=nullptr;
        }else{
            deleteleaf(p->Lchild);
            deleteleaf(p->Rchild);
        }
    }
}
void bst::inorder(node *p){
    if(p){
        inorder(p->Lchild);
        cout<<p->data<<" "<<flush;
        inorder(p->Rchild);
    }
};
void bst::Insert(int key){
    node* t = bt;
    node* x;
     node* r;
     //Empty root
    if(bt==nullptr){
        x = new node;
        x->data = key;
        x->Lchild =nullptr;
        x->Rchild = nullptr;
        bt = x;
        return;
        }
    while(t!=nullptr){
        r=t;
    if(key == t->data){
        return;
    }else if(key>t->data){
        t=t->Rchild;
    }else{
        t=t->Lchild;
    }
    }
    x = new node;
    x->data = key;
    x->Lchild=nullptr;
    x->Rchild=nullptr;
    if(key>r->data){
        r->Rchild=x;
    }else{
        r->Lchild=x;
    }
    // bt=r;
}
node* bst::Rsearch(node *p,int key){
    if(p==nullptr){
        return nullptr;
    }else if(key == p->data){
        return p;
    }else if(key>p->data){
        return Rsearch(p->Rchild,key);
    }else{
        return Rsearch(p->Lchild,key);
    }
}

int main(void){
    bst b;
    for(int i=100;i>0;i=i-2){
        b.Insert(i);
    }
    b.inorder();
    cout<<endl;
    b.inorder(b.Rsearch(40));
    // cout<<endl;
    // b.deleteleaf();
    // b.inorder();
    cout<<endl;
    b.deletebt(40);
    b.inorder();
    cout<<"great sum"<<endl;
    b.greatsum();
    b.inorder();
    return 0;
}