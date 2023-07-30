#include<iostream>
#include <queue>

using namespace std;

typedef struct node{
    node* lchild;
    int data;
    node* rchild;
} node;

class tree{

    private:
        node* root;
    public:
        tree();
        void createtree();
        int height(node* node);
        void inorder(node* p);
        void preorder(node* p);
        void postorder(node* p);
        void levelorder(node* p);
        int leafnode(node* p);
        int count(node *p);
        void printCurrentLevel(node* p, int level);
        int height(){
            return height(root);
        }
        void inorder(){inorder(root);}
        void preorder(){preorder(root);};
        void postorder(){postorder(root);};
        void levelorder(){levelorder(root);};
        ~tree(){
            delete root;
        }

};

int tree::leafnode(node* p){
    int x;
    int y;
    if(p!=nullptr){
        x=leafnode(p->lchild);
        y=leafnode(p->rchild);
        if(p->lchild==nullptr && p->rchild==nullptr){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int tree::count(node* p){
    int l;
    int r;
    if(p!=nullptr){
        l=count(p->lchild);
        r=count(p->rchild);
        return l+r+1;
    }
    return 0;
}

void tree::printCurrentLevel(node* p,int level){
    if (p == NULL)
        return;
    if (level == 1)
        cout << p->data << " ";
    else if (level > 1) {
        printCurrentLevel(p->lchild, level - 1);
        printCurrentLevel(p->rchild, level - 1);
    }
}

int tree::height(node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->lchild);
        int rheight = height(node->rchild);
 
        // Use the larger one
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

tree::tree(){
    root=nullptr;
}

void tree::createtree(){
    node *p;
    node *t;
    int x;
    queue<node*> q;

    root = new node;
    cout<<"enter root data "<<flush;
    cin>>root->data;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.emplace(root);

    while(!q.empty()){
        p=q.front();
        q.pop();

        cout<<"enter left child value of "<<p->data<<" "<<flush;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.emplace(t);
        }

        cout<<"enter right child value of "<<p->data<<" "<<flush;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.emplace(t);
        }
    }
}

void tree::inorder(node* p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" "<<flush;
        inorder(p->rchild);
    }
}

void tree::preorder(node* p){
    if(p){
        cout<<p->data<<" "<<flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::postorder(node* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" "<<flush;
    }
}

void tree::levelorder(node* p){
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main(void){

    tree bt;
    bt.createtree();
    cout<<endl;

    cout<<"inorder "<<endl;
    bt.inorder();
    cout<<endl;
    cout<<"preorder "<<endl;
    bt.preorder();
    cout<<endl;
    cout<<"postorder "<<endl;
    bt.postorder();
    cout<<endl;
    cout<<"levelorder "<<endl;
    bt.levelorder();
    cout<<endl;
    return 0;
}