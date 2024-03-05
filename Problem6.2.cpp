#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using  namespace std;

template<class T>
class BST;

template<class T>
class Node
{
    T data;
    Node<T>*left,*right;
    int childs;

public:

    Node():left(nullptr),right(nullptr),childs(0){}
    Node(const T&x):data(x),left(nullptr),right(nullptr),childs(0){}
    ~Node()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }

    friend class BST<T>;

    void insert(const T&x)
    {
      //  childs++;
        if(data==x)
            return;

         childs++;
        if(x<data)
        {
            if(left)
                left->insert(x);
            else
            {
                left=new Node<T>(x);
                return;
            }
        }
        if(x>data)
        {
            if(right)
                right->insert(x);
            else
            {
                right=new Node<T>(x);
                return;
            }
        }
    }

    void InOrder()
    {
        if(left)
            left->InOrder();
        cout<<data<<" copii: "<<childs<<endl;
        if(right)
            right->InOrder();
    }

    void dist(int &d)
    {
        d++;
        if(left== nullptr && right== nullptr)
        {
            return;
        }

        if(left && right== nullptr)
        {
            left->dist(d);
        }

        if(left== nullptr && right)
        {
            right->dist(d);
        }

        if(left && right)
        {
            int l=0,r=0;
            left->dist(l);
            right->dist(r);
            int max=(l>r)?l:r;
            d=d+max;
            return;
        }
    }

    void solve(T&x)
    {
            int dl=0;
            int dr=0;

            if(left)
                left->dist(dl);
            if(right)
                right->dist(dr);
            int max=dl+dr;
            if(max>x)
                x=max;
        if(left)
            left->solve(x);
        if(right)
            right->solve(x);

    }

};

template <class T>
class BST
{
    Node<T>*root;

public:
    BST():root(nullptr){}
    ~BST()
    {
        if(root)
            delete root;
    }

    void insert(const T&x)
    {
        if(root== nullptr)
        {
            root=new Node<T>(x);
            return;
        }
        root->insert(x);
    }

    void InOrder()
    {
        if(root)
            root->InOrder();
    }

    void solve(T &x)
    {
        if(root)
        {
            root->solve(x);
        }
    }

};

int main()
{
    int n;
    cin>>n;
    BST<int> myTree;
    for(int i=0;i<n;++i)
    {
        int aux;
        cin>>aux;
        myTree.insert(aux);
    }
    int nod=0;
    myTree.solve(nod);
    cout<<nod;

    return 0;
}
