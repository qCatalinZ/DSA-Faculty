#include <iostream>
using namespace std;

template <class T>
class List;

template<class T>
struct Node
{
    T info;
    Node<T> *next;

//public:

    Node():info(T()),next(nullptr){}

    ~Node()=default;

    Node(const T &a):info(a),next(nullptr){}

    friend class List<T>;

};

template<class T>
class List
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:

    List():size(0),head(nullptr),tail(nullptr){}

    ~List()
    {
        if(head)
        {
            while(head->next)
            {
                auto tmp=head;
                head=head->next;
                delete tmp;
            }
            delete head;
            head=nullptr;
            tail=nullptr;
            size=0;
        }
    }

    void print()
    {
        if(head)
        {
            cout<<size<<endl;
            auto tmp=head;
            while(tmp->next)
            {
                cout<<tmp->info<<" ";
                tmp=tmp->next;
            }
            cout<<tail->info<<" "<<endl;
        }
    }

    void push_back(const T& d)
    {
        if(head==nullptr)
        {
            head=new Node<T>(d);
            tail=head;
            size++;
            return;
        }
        tail->next=new Node<T>(d);
        tail=tail->next;
        tail->next=nullptr;
        size++;
    }

    void push_front(const T& d)
    {
        if(head==nullptr)
        {
            head=new Node<T>(d);
            tail=head;
            return;
        }
        size++;
        auto tmp=new Node<T>(d);
        tmp->next=head;
        head=tmp;
    }

    T getHead()
    {
        return head->info;
    }

    T getTail()
    {
        return tail->info;
    }

    void pop_front()
    {
        if(head==nullptr)
            return;
        if(head->next==nullptr)
        {
            delete head;
            size--;
            head=nullptr;
            tail=nullptr;
            return;
        }
        auto tmp=head;
        head=head->next;
        delete tmp;
        size--;
    }

    void pop_back()
    {
        if(head==nullptr)
            return;
        if(head->next==nullptr)
        {
            delete head;
            head=nullptr;
            tail=nullptr;
            size--;
            return;
        }

        auto tmp=head;
        while(tmp->next != tail)
        {
            tmp=tmp->next;
        }
        delete tail;
        tail=tmp;
        tail->next=nullptr;

        size--;
    }

    int getSize()
    {
        return size;
    }

    void insert(int p,const T& d)
    {
        if(p<1 || p>size)
            return;

        if(p==1)
        {
            push_front(d);
            return;
        }

        auto newNode=new Node<T>(d);
        auto tmp=head;
        if(p==size)
        {
            while(tmp->next != tail)
            {
                tmp=tmp->next;
            }
            newNode->next=tail;
            tmp->next=newNode;
            size++;
            return;
        }

        p--;
        while(p!=1)
        {
            tmp=tmp->next;
            p--;
        }
        newNode->next=tmp->next;
        tmp->next=newNode;
        size++;
    }

    void erase(int p)
    {
        if(p<1 || p>size)
            return;
        if(p==1)
        {
            pop_front();
            return;
        }
        if(p==size)
        {
            pop_back();
            return;
        }

        size--;
        auto tmp=head;
        p--;
        while(p!=1)
        {
            tmp=tmp->next;
            p--;
        }
        auto del=tmp->next;
        tmp->next=tmp->next->next;
        delete del;
    }

    T operator[](const int &index)
    {
        if(index<0 || index>=size)
            return T();
        if(index==0)
        {
            return head->info;
        }
        if(index==size-1)
        {
            return tail->info;
        }
        auto tmp=head;
        for(int i=0;i<index;++i)
            tmp=tmp->next;
        return tmp->info;
    }


    Node<T> *begin()
    {
        return head;
    }

    Node<T> *end()
    {
        return nullptr;
    }

};

int main()
{
    List<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    for (Node<int>* current = myList.begin(); current != myList.end(); current = current->next)
    {
        cout<<current->info<<" ";
    // Proceseazã nodul curent
    }


    /// TESTARE IMPLEMENTARE
    /*
  //  myList.print();

    for(int i=0;i<5;++i)
    {
        myList.push_back(i);
    }
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    for(int i=-2;i<=-1;++i)
    {
        myList.push_front(i);
    }
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.pop_front();
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.pop_back();
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.insert(1,69);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.insert(6,69);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.insert(2,69);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.erase(1);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.erase(7);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.erase(4);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    myList.erase(2);
    myList.print();
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;

    cout<<"FOLOSIRE OPERATOR INDEX:"<<endl;
    for(int i=0;i<myList.getSize();++i)
        cout<<myList[i]<<" ";
    cout<<endl;
    cout<<myList.getHead()<<" "<<myList.getTail()<<endl;
    */



    return 0;
}
