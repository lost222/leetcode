#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node * Next;
    Node (){
        val = 0;
        Next = NULL;
    };
    Node(int v){
        val = v;
        Next = NULL;
    }
};

class chain{
public:
    Node head;
    chain(){
        head.val = 0;
        head.Next = NULL;
    }

    void out(){
        Node *n = head.Next;
        while(n != NULL) {
            cout<<n->val<<" ";
            n = n->Next;
        }
    }

    void revese(){
        Node *f = head.Next;
        if(f == NULL){return ;}
        Node *r = f->Next;

        while(r != NULL){
          //  cout<<r->val<<" ";
            Node * p = r;
            r = r->Next;
            p->Next = f;
            f = p;
        }
        head.Next->Next = NULL;
        head.Next = f;


        return ;
    }

};


int main() {
    cout << "Hello World!" << endl;

    chain S;
    Node a(1),b(2),c(3);
    S.head.Next = &a;
    a.Next = &b;
    b.Next = &c;

    S.out();

    S.revese();

    S.out();




}