#include <cstring>
#include <vector>
using namespace std;

template<class T>
class BST;

template <class T>
class Node
{
    T info;
    Node<T>*left,*right;

public:
    Node():left(nullptr),right(nullptr){}
    Node(const T&x):info(x),left(nullptr),right(nullptr){}
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
        if(x>info)
        {
            if(right)
            {
                right->insert(x);
            }
            else
            {
                right=new Node<T>(x);
                return;
            }
        }
        else if(x<info)
        {
            if(left)
            {
                left->insert(x);
            }
            else
            {
                left=new Node<T>(x);
                return;
            }
        }
    }

    void PostOrder()
    {
        if(left)
            left->PostOrder();
        if(right)
            right->PostOrder();
        cout<<info<<" ";
    }
};

template<class T>
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

    void PostOrder()
    {
        if(root== nullptr)
        {
            return;
        }
        root->PostOrder();
    }
};

int main()
{
    BST<int> arbore;
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        arbore.insert(tmp);
    }
    arbore.PostOrder();

    return 0;
}
